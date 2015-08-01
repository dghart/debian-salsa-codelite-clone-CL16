//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: WebToolsBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_WEBTOOLS_WEBTOOLSBASE_BASE_CLASSES_H
#define CODELITE_WEBTOOLS_WEBTOOLSBASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/checkbox.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/splitter.h>
#include <wx/dataview.h>
#include "m_dataview126model.h"
#include "Notebook.h"
#include <wx/bitmap.h>
#include <map>
#include <wx/icon.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class WebToolsSettingsBase : public wxDialog
{
protected:
    wxNotebook* m_notebook10;
    wxPanel* m_panel56;
    wxCheckBox* m_checkBoxEnableJsCC;
    wxCheckBox* m_checkBoxEnableXmlCC;
    wxCheckBox* m_checkBoxEnableHtmlCC;
    wxPanel* m_panel12;
    wxPropertyGridManager* m_pgMgr;
    wxPGProperty* m_pgProp26;
    wxPGProperty* m_pgPropLogging;
    wxPGProperty* m_pgProp32;
    wxPGProperty* m_pgPropEcma5;
    wxPGProperty* m_pgPropEcma6;
    wxPGProperty* m_pgPropJQuery;
    wxPGProperty* m_pgPropUnderscore;
    wxPGProperty* m_pgPropBrowser;
    wxPGProperty* m_pgPropChai;
    wxPGProperty* m_pgPropQML;
    wxPGProperty* m_pgProp46;
    wxPGProperty* m_pgPropAngular;
    wxPGProperty* m_pgPropStrings;
    wxPGProperty* m_pgPropNode;
    wxPGProperty* m_pgPropRequireJS;
    wxStdDialogButtonSizer* m_stdBtnSizer4;
    wxButton* m_buttonCancel;
    wxButton* m_buttonOK;

protected:
    virtual void OnModified(wxCommandEvent& event) { event.Skip(); }
    virtual void OnJSValueChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBoxEnableJsCC() { return m_checkBoxEnableJsCC; }
    wxCheckBox* GetCheckBoxEnableXmlCC() { return m_checkBoxEnableXmlCC; }
    wxCheckBox* GetCheckBoxEnableHtmlCC() { return m_checkBoxEnableHtmlCC; }
    wxPanel* GetPanel56() { return m_panel56; }
    wxPropertyGridManager* GetPgMgr() { return m_pgMgr; }
    wxPanel* GetPanel12() { return m_panel12; }
    wxNotebook* GetNotebook10() { return m_notebook10; }
    WebToolsSettingsBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("WebTools Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~WebToolsSettingsBase();
};


class NodeJSDebuggerDlgBase : public wxDialog
{
protected:
    wxStaticText* m_staticText78;
    wxFilePickerCtrl* m_filePickerNodeJS;
    wxStaticText* m_staticTextScript;
    wxFilePickerCtrl* m_filePickerScript;
    wxStaticText* m_staticTextDebuggerPort;
    wxTextCtrl* m_textCtrlPort;
    wxStaticText* m_staticText132;
    wxStyledTextCtrl* m_stcCommandLineArguments;
    wxStdDialogButtonSizer* m_stdBtnSizer70;
    wxButton* m_buttonOK;
    wxButton* m_button74;

protected:
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText78() { return m_staticText78; }
    wxFilePickerCtrl* GetFilePickerNodeJS() { return m_filePickerNodeJS; }
    wxStaticText* GetStaticTextScript() { return m_staticTextScript; }
    wxFilePickerCtrl* GetFilePickerScript() { return m_filePickerScript; }
    wxStaticText* GetStaticTextDebuggerPort() { return m_staticTextDebuggerPort; }
    wxTextCtrl* GetTextCtrlPort() { return m_textCtrlPort; }
    wxStaticText* GetStaticText132() { return m_staticText132; }
    wxStyledTextCtrl* GetStcCommandLineArguments() { return m_stcCommandLineArguments; }
    NodeJSDebuggerDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Node.js Debugger"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~NodeJSDebuggerDlgBase();
};


class NodeJSDebuggerPaneBase : public wxPanel
{
protected:
    wxSplitterWindow* m_splitter104;
    wxPanel* m_splitterPage112;
    wxDataViewCtrl* m_dataviewLocals;
    wxObjectDataPtr<m_dataview126Model> m_dataviewLocalsModel;

    wxPanel* m_splitterPage108;
    wxSplitterWindow* m_splitter168;
    wxPanel* m_splitterPage172;
    wxDataViewListCtrl* m_dvListCtrlCallstack;
    wxPanel* m_splitterPage176;
    Notebook* m_notebook;
    wxPanel* m_panelConsoleLog;
    wxStyledTextCtrl* m_consoleLog;
    wxTextCtrl* m_textCtrlExpression;
    wxPanel* m_panelBreakpoints;
    wxDataViewListCtrl* m_dvListCtrlBreakpoints;

protected:
    virtual void OnItemActivated(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnEvaluateExpression(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBreakpointSelected(wxDataViewEvent& event) { event.Skip(); }

public:
    wxDataViewCtrl* GetDataviewLocals() { return m_dataviewLocals; }
    wxPanel* GetSplitterPage112() { return m_splitterPage112; }
    wxDataViewListCtrl* GetDvListCtrlCallstack() { return m_dvListCtrlCallstack; }
    wxPanel* GetSplitterPage172() { return m_splitterPage172; }
    wxStyledTextCtrl* GetConsoleLog() { return m_consoleLog; }
    wxTextCtrl* GetTextCtrlExpression() { return m_textCtrlExpression; }
    wxPanel* GetPanelConsoleLog() { return m_panelConsoleLog; }
    wxDataViewListCtrl* GetDvListCtrlBreakpoints() { return m_dvListCtrlBreakpoints; }
    wxPanel* GetPanelBreakpoints() { return m_panelBreakpoints; }
    Notebook* GetNotebook() { return m_notebook; }
    wxPanel* GetSplitterPage176() { return m_splitterPage176; }
    wxSplitterWindow* GetSplitter168() { return m_splitter168; }
    wxPanel* GetSplitterPage108() { return m_splitterPage108; }
    wxSplitterWindow* GetSplitter104() { return m_splitter104; }
    NodeJSDebuggerPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,250), long style = wxTAB_TRAVERSAL);
    virtual ~NodeJSDebuggerPaneBase();
};


class NodeJSNewWorkspaceDlgBase : public wxDialog
{
protected:
    wxStaticText* m_staticText150;
    wxDirPickerCtrl* m_dirPickerFolder;
    wxStaticText* m_staticText160;
    wxTextCtrl* m_textCtrllName;
    wxCheckBox* m_checkBoxNewFolder;
    wxStaticText* m_staticTextPreview;
    wxStdDialogButtonSizer* m_stdBtnSizer142;
    wxButton* m_button144;
    wxButton* m_button146;

protected:
    virtual void OnFolderSelected(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnTextUpdate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCheckNewFolder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText150() { return m_staticText150; }
    wxDirPickerCtrl* GetDirPickerFolder() { return m_dirPickerFolder; }
    wxStaticText* GetStaticText160() { return m_staticText160; }
    wxTextCtrl* GetTextCtrllName() { return m_textCtrllName; }
    wxCheckBox* GetCheckBoxNewFolder() { return m_checkBoxNewFolder; }
    wxStaticText* GetStaticTextPreview() { return m_staticTextPreview; }
    NodeJSNewWorkspaceDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New Workspace"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~NodeJSNewWorkspaceDlgBase();
};


class WebToolsImages : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    WebToolsImages();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
    }
    virtual ~WebToolsImages();
};

#endif
