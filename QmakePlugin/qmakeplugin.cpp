#include <wx/xrc/xmlres.h>
#include "globals.h"
#include "dirsaver.h"
#include "newqtprojdlg.h"
#include "procutils.h"
#include "project.h"
#include "workspace.h"
#include <wx/app.h>
#include "build_settings_config.h"
#include "qmakegenerator.h"
#include <wx/log.h>
#include <wx/menu.h>
#include "qmakeplugin.h"
#include "qmakesettingsdlg.h"
#include "qmaketab.h"
#include "qmakeconf.h"
#include "build_system.h"

static QMakePlugin* thePlugin = NULL;

//Define the plugin entry point
extern "C" EXPORT IPlugin *CreatePlugin(IManager *manager)
{
	if (thePlugin == 0) {
		thePlugin = new QMakePlugin(manager);
	}
	return thePlugin;
}

extern "C" EXPORT PluginInfo GetPluginInfo()
{
	PluginInfo info;
	info.SetAuthor(wxT("Eran Ifrah"));
	info.SetName(wxT("QMakePlugin"));
	info.SetDescription(wxT("Qt's QMake integration with CodeLite"));
	info.SetVersion(wxT("v1.0"));
	return info;
}

extern "C" EXPORT int GetPluginInterfaceVersion()
{
	return PLUGIN_INTERFACE_VERSION;
}

QMakePlugin::QMakePlugin(IManager *manager)
		: IPlugin(manager)
{
	m_longName = wxT("Qt's QMake integration with CodeLite");
	m_shortName = wxT("QMakePlugin");
	m_conf = new QmakeConf(m_mgr->GetStartupDirectory() + wxT("/config/qmake.ini"));

	//Connect items
	wxApp *app = m_mgr->GetTheApp();

	app->Connect(wxEVT_CMD_PROJ_SETTINGS_SAVED, wxCommandEventHandler(QMakePlugin::OnSaveConfig     ), NULL, this);
	app->Connect(wxEVT_BUILD_STARTING,          wxCommandEventHandler(QMakePlugin::OnBuildStarting  ), NULL, this);
	app->Connect(wxEVT_GET_PROJECT_BUILD_CMD,   wxCommandEventHandler(QMakePlugin::OnGetBuildCommand), NULL, this);
	app->Connect(wxEVT_GET_PROJECT_CLEAN_CMD,   wxCommandEventHandler(QMakePlugin::OnGetCleanCommand), NULL, this);
	app->Connect(wxEVT_GET_IS_PLUGIN_MAKEFILE,  wxCommandEventHandler(QMakePlugin::OnGetIsPluginMakefile), NULL, this);
}

QMakePlugin::~QMakePlugin()
{
	UnPlug();
	delete m_conf;
}

wxToolBar *QMakePlugin::CreateToolBar(wxWindow *parent)
{
	// Create the toolbar to be used by the plugin
	wxToolBar *tb(NULL);

	// You can use the below code a snippet:
	// First, check that CodeLite allows plugin to register plugins
	if (m_mgr->AllowToolbar()) {
		// Support both toolbars icon size
		int size = m_mgr->GetToolbarIconSize();

		// Allocate new toolbar, which will be freed later by CodeLite
		tb = new wxToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT | wxTB_NODIVIDER);

		// Set the toolbar size
		tb->SetToolBitmapSize(wxSize(size, size));

		// Add tools to the plugins toolbar. You must provide 2 sets of icons: 24x24 and 16x16
		if (size == 24) {
			tb->AddTool(XRCID("qmake_settings"), wxT("Configure qmake"), LoadBitmapFile(wxT("qt24_preferences.png")), wxT("Configure qmake"));
			tb->AddTool(XRCID("new_qmake_project"), wxT("Create new qmake based project"), LoadBitmapFile(wxT("qt24_new.png")), wxT("Create new qmake based project"));
		} else {
			tb->AddTool(XRCID("qmake_settings"), wxT("Configure qmake"), LoadBitmapFile(wxT("qt16_preferences.png")), wxT("Configure qmake"));
			tb->AddTool(XRCID("new_qmake_project"), wxT("Create new qmake based project"), LoadBitmapFile(wxT("qt16_new.png")), wxT("Create new qmake based project"));
		}
		// And finally, we must call 'Realize()'
		tb->Realize();
	}

	// return the toolbar, it can be NULL if CodeLite does not allow plugins to register toolbars
	// or in case the plugin simply does not require toolbar

	return tb;
}

void QMakePlugin::CreatePluginMenu(wxMenu *pluginsMenu)
{
	// You can use the below code a snippet:
	wxMenu *menu = new wxMenu();
	wxMenuItem *item(NULL);
	item = new wxMenuItem(menu, XRCID("new_qmake_project"), _("New qmake based project..."), wxEmptyString, wxITEM_NORMAL);
	menu->Append(item);

	item = new wxMenuItem(menu, XRCID("qmake_settings"), _("Settings..."), wxEmptyString, wxITEM_NORMAL);
	menu->Append(item);

	pluginsMenu->Append(wxID_ANY, _("QMake"), menu);

	m_mgr->GetTheApp()->Connect(XRCID("new_qmake_project"), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(QMakePlugin::OnNewQmakeBasedProject), NULL, (wxEvtHandler*)this);
	m_mgr->GetTheApp()->Connect(XRCID("qmake_settings"), wxEVT_COMMAND_MENU_SELECTED,    wxCommandEventHandler(QMakePlugin::OnSettings), NULL, (wxEvtHandler*)this);
}

void QMakePlugin::HookPopupMenu(wxMenu *menu, MenuType type)
{
	wxUnusedVar( menu );
	wxUnusedVar( type );
}

void QMakePlugin::UnHookPopupMenu(wxMenu *menu, MenuType type)
{
	wxUnusedVar( menu );
	wxUnusedVar( type );
}

void QMakePlugin::UnPlug()
{
	wxApp *app = m_mgr->GetTheApp();
	app->Disconnect(wxEVT_CMD_PROJ_SETTINGS_SAVED, wxCommandEventHandler(QMakePlugin::OnSaveConfig     ),     NULL, this);
	app->Disconnect(wxEVT_BUILD_STARTING,          wxCommandEventHandler(QMakePlugin::OnBuildStarting  ),     NULL, this);
	app->Disconnect(wxEVT_GET_PROJECT_BUILD_CMD,   wxCommandEventHandler(QMakePlugin::OnGetBuildCommand),     NULL, this);
	app->Disconnect(wxEVT_GET_PROJECT_CLEAN_CMD,   wxCommandEventHandler(QMakePlugin::OnGetCleanCommand),     NULL, this);
	app->Disconnect(wxEVT_GET_IS_PLUGIN_MAKEFILE,  wxCommandEventHandler(QMakePlugin::OnGetIsPluginMakefile), NULL, this);
}

void QMakePlugin::HookProjectSettingsTab(wxNotebook* book, const wxString &projectName, const wxString &configName)
{
	if ( !book ) return;

	DoUnHookAllTabs(book);

	QMakeTab *page = DoGetQmakeTab(configName);
	if (! page ) {
		page = new QMakeTab(book, m_conf);
		page->Load(m_mgr, projectName, configName);
		m_pages[configName] = page;
	}
	book->AddPage(page, wxT("QMake"), true, wxNOT_FOUND);
}

void QMakePlugin::UnHookProjectSettingsTab(wxNotebook* book, const wxString &projectName, const wxString &configName)
{
	wxUnusedVar( configName );
	DoUnHookAllTabs(book);
}

void QMakePlugin::OnSaveConfig(wxCommandEvent& event)
{
	event.Skip();

	wxString *proj = (wxString *)event.GetClientData();

	wxString conf, project;
	project = *proj;
	conf    = event.GetString();

	QMakeTab *tab = DoGetQmakeTab( conf );
	if ( !tab ) {
		return;
	}
	tab->Save(m_mgr, project, conf);
}

QMakeTab* QMakePlugin::DoGetQmakeTab(const wxString& config)
{
	std::map<wxString, QMakeTab*>::iterator iter = m_pages.find(config);
	if (iter == m_pages.end()) {
		return NULL;
	}
	return iter->second;
}

void QMakePlugin::DoUnHookAllTabs(wxNotebook* book)
{
	if ( !book ) {
		return;
	}

	for (size_t i=0 ; i<book->GetPageCount(); i++) {
		std::map<wxString, QMakeTab*>::iterator iter = m_pages.begin();
		for (; iter != m_pages.end(); iter++) {
			if (book->GetPage(i) == iter->second) {
				book->RemovePage(i);
				iter->second->Destroy();
				m_pages[iter->first] = NULL;
				break;
			}
		}
	}
	book->Layout();
}

void QMakePlugin::OnSettings(wxCommandEvent& event)
{
	QMakeSettingsDlg dlg(NULL, m_mgr, m_conf);
	dlg.ShowModal();
}

void QMakePlugin::OnBuildStarting(wxCommandEvent& event)
{
	// call Skip() to allow the standard compilation to take place
	event.Skip();

	QmakePluginData::BuildConfPluginData bcpd;

	wxString *cd = (wxString *)event.GetClientData();
	wxString  project = *cd;
	wxString  config  = event.GetString();

	if ( !DoGetData(project, config, bcpd) ) {
		return;
	}

	if ( !bcpd.m_enabled ) {
		return;
	}

	wxString errMsg;
	ProjectPtr p = m_mgr->GetWorkspace()->FindProjectByName(project, errMsg);
	if ( !p ) {
		return;
	}
	QMakeProFileGenerator generator(m_mgr, project, config);

	// regenrate the .pro file
	bool needRegeneration = generator.Generate();

	wxString qmake_exe = m_conf->Read(wxString::Format(wxT("%s/qmake"),     bcpd.m_qmakeConfig.c_str()));
	wxString qmakespec = m_conf->Read(wxString::Format(wxT("%s/qmakespec"), bcpd.m_qmakeConfig.c_str()));
	wxString qtdir     = m_conf->Read(wxString::Format(wxT("%s/qtdir"),     bcpd.m_qmakeConfig.c_str()));

	// Create qmake comand
	wxString qmake_exe_line;
	qmake_exe.Trim().Trim(false);
	qmakespec.Trim().Trim(false);

	// Set QTDIR
	DirSaver ds;
	{

		wxSetWorkingDirectory ( p->GetFileName().GetPath(wxPATH_GET_SEPARATOR|wxPATH_GET_VOLUME) );
		wxSetEnv(wxT("QTDIR"), qtdir);
		qmake_exe_line << wxT("\"") << qmake_exe << wxT("\" -spec ") << qmakespec << wxT(" ") << generator.GetProFileName();

		if ( needRegeneration ) {
			wxArrayString output;
			ProcUtils::SafeExecuteCommand(qmake_exe_line, output);
		}

	}
}

bool QMakePlugin::DoGetData(const wxString& project, const wxString& conf, QmakePluginData::BuildConfPluginData &bcpd)
{
	wxString errMsg;
	ProjectPtr p = m_mgr->GetWorkspace()->FindProjectByName(project, errMsg);
	if ( p ) {
		wxString rawData = p->GetPluginData(wxT("qmake"));
		QmakePluginData pd( rawData );
		return pd.GetDataForBuildConf(conf, bcpd);
	}
	return false;
}

void QMakePlugin::OnGetCleanCommand(wxCommandEvent& event)
{
	QmakePluginData::BuildConfPluginData bcpd;

	wxString *cd = (wxString *)event.GetClientData();
	wxString  project = *cd;
	wxString  config  = event.GetString();

	if ( !DoGetData(project, config, bcpd) ) {
		event.Skip();
		return;
	}

	if ( !bcpd.m_enabled ) {
		event.Skip();
		return;
	}

	event.SetString( DoGetBuildCommand(project, config, event.GetInt() == 1) + wxT(" clean") );
}

void QMakePlugin::OnGetBuildCommand(wxCommandEvent& event)
{
	QmakePluginData::BuildConfPluginData bcpd;

	wxString *cd = (wxString *)event.GetClientData();
	wxString  project = *cd;
	wxString  config  = event.GetString();

	if ( !DoGetData(project, config, bcpd) ) {
		event.Skip();
		return;
	}

	if ( !bcpd.m_enabled ) {
		event.Skip();
		return;
	}

	event.SetString( DoGetBuildCommand(project, config, event.GetInt() == 1) );
}

void QMakePlugin::OnGetIsPluginMakefile(wxCommandEvent& event)
{
	QmakePluginData::BuildConfPluginData bcpd;

	wxString *cd = (wxString *)event.GetClientData();
	wxString  project = *cd;
	wxString  config  = event.GetString();

	if ( !DoGetData(project, config, bcpd) ) {
		event.Skip();
		return;
	}

	if ( bcpd.m_enabled ) {
		// return without calling event.Skip()
		return;
	}
	event.Skip();
}

wxString QMakePlugin::DoGetBuildCommand(const wxString &project, const wxString &config, bool projectOnly)
{
	wxUnusedVar ( config );

	wxString errMsg;
	ProjectPtr p = m_mgr->GetWorkspace()->FindProjectByName(project, errMsg);
	if ( !p ) {
		return wxEmptyString;
	}

	BuildSystemPtr bsptr = m_mgr->GetBuildSettingsConfigManager()->GetBuildSystem(wxT ( "GNU makefile for g++/gcc" ));
	wxString buildTool   = bsptr->GetToolPath();
	buildTool            = m_mgr->GetWorkspace()->ExpandVariables(buildTool);
	wxString jobs        = bsptr->GetToolJobs();

	// fix: replace all Windows like slashes to POSIX
	buildTool.Replace(wxT("\\"), wxT("/"));

	wxString cmd;

	if ( !projectOnly ) {
		cmd << wxT("@cd \"") << p->GetFileName().GetPath() << wxT("\" && ");
	}

	cmd << wxT("\"") << buildTool << wxT("\" ") << wxT("-j ");
	if ( jobs != wxT("unlimited") ) {
		cmd << jobs << wxT(" ");
	}
	cmd << bsptr->GetToolOptions() << wxT(" ");
	cmd << wxT("\"") << p->GetName() << wxT(".mk\"");
	return cmd;
}

void QMakePlugin::OnNewQmakeBasedProject(wxCommandEvent& event)
{
	wxUnusedVar ( event );
	if (m_conf->GetAllConfigurations().IsEmpty()) {
		wxMessageBox(wxT("There is no qmake defined, please define one from 'Plugins -> Qmake -> Settings'"), wxT("CodeLite"), wxOK|wxICON_WARNING|wxCENTER, m_mgr->GetTheApp()->GetTopWindow());
		return;
	}

	NewQtProjDlg dlg(m_mgr->GetTheApp()->GetTopWindow(), m_conf, m_mgr);
	if (dlg.ShowModal() == wxID_OK) {
		wxString kind         = dlg.GetProjectKind();
		wxString name         = dlg.GetProjectName();
		wxString path         = dlg.GetProjectPath();
		wxString configRelease= wxT("0000");
		wxString config       = wxT("0000");
		wxString templateFile = m_mgr->GetStartupDirectory();
		wxString type         = wxEmptyString;
		wxString qmakeSettings= dlg.GetQmake();
		wxString qmake;
		wxString content;

		if ( kind == wxT("Static Library") ) {

			type = Project::STATIC_LIBRARY;

		} else if ( kind == wxT("Dynamic Library") ) {

			type = Project::DYNAMIC_LIBRARY;

		} else if ( kind == wxT("Console") ) {

			type = Project::EXECUTABLE;
			configRelease = wxT("0017CONFIG += console");
			config        = wxT("0023CONFIG += console debug");

		} else {

			type = Project::EXECUTABLE;
			config        = wxT("0015CONFIG += debug");
			configRelease = wxT("0000");
		}

		wxString filename(m_mgr->GetStartupDirectory() + wxT("/templates/qmake/qmake.project"));
		if (!ReadFileWithConversion(filename, content)) {
			return;
		}

		// prepend the string lenght
		qmake = wxString::Format(wxT("%04d%s"), qmakeSettings.Length(), qmakeSettings.c_str());


		content.Replace(wxT("$(TYPE)")  ,         type);
		content.Replace(wxT("$(NAME)")  ,         name);
		content.Replace(wxT("$(CONFIG)"),         config);
		content.Replace(wxT("$(RELEASE_CONFIG)"), configRelease);
		content.Replace(wxT("$(QMAKE)"),          qmake);

		//save the file to the disk
		{
			DirSaver ds;
			if ( !wxSetWorkingDirectory(path) ) {
				wxMessageBox(_("Invalid project path!"), wxT("CodeLite"), wxOK|wxCENTER|wxICON_WARNING);
				return;
			}

			if ( dlg.GetCreateDirectory() ) {
				wxMkdir(name);
				wxSetWorkingDirectory(name);
			}

			if ( !WriteFileWithBackup(name + wxT(".project"), content, false) ) {
				wxMessageBox(wxString::Format(_("Failed to create .project file '%s'"), wxString(name + wxT(".project")).c_str()),
				             wxT("CodeLite"), wxOK|wxCENTER|wxICON_WARNING);
				return;
			}

			path = wxGetCwd();
			path << wxFileName::GetPathSeparator() << name << wxT(".project");

			m_mgr->AddProject(path);
		}
	}
}