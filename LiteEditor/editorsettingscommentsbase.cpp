//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: editor_options_comments_base.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editorsettingscommentsbase.h"


// Declare the bitmap loading function
extern void wxCD0F0InitBitmapResources();

static bool bBitmapLoaded = false;


EditorSettingsCommentsBase::EditorSettingsCommentsBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCD0F0InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    wxBoxSizer* bSizer2 = new wxBoxSizer(wxVERTICAL);
    
    mainSizer->Add(bSizer2, 0, wxALL|wxEXPAND, 5);
    
    m_checkBoxSmartAddFiles = new wxCheckBox(this, wxID_ANY, _("When adding new files to a project, place the files in the 'include' / 'src' folders respectively"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxSmartAddFiles->SetValue(false);
    
    bSizer2->Add(m_checkBoxSmartAddFiles, 0, wxALL, 10);
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer2->Add(boxSizer1, 0, wxALL|wxEXPAND, 5);
    
    m_staticText3 = new wxStaticText(this, wxID_ANY, _("Comments:"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_staticText3->Enable(false);
    
    boxSizer1->Add(m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLI_HORIZONTAL);
    
    boxSizer1->Add(m_staticline1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    wxBoxSizer* boxSizer4 = new wxBoxSizer(wxVERTICAL);
    
    bSizer2->Add(boxSizer4, 0, wxALL, 5);
    
    m_checkBoxContCComment = new wxCheckBox(this, wxID_ANY, _("Hitting <ENTER> in a C style comment automatically adds a '*' to the next line"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxContCComment->SetValue(true);
    
    boxSizer4->Add(m_checkBoxContCComment, 0, wxALL, 5);
    
    m_checkBoxContinueCppComment = new wxCheckBox(this, wxID_ANY, _("Hitting <ENTER> in a C++ style comment section automatically adds a'//' to the next line"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxContinueCppComment->SetValue(false);
    
    boxSizer4->Add(m_checkBoxContinueCppComment, 0, wxALL, 5);
    
    wxBoxSizer* boxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer2->Add(boxSizer5, 0, wxALL|wxEXPAND, 5);
    
    m_staticText7 = new wxStaticText(this, wxID_ANY, _("Code Navigation Accelerators:"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_staticText7->Enable(false);
    
    boxSizer5->Add(m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLI_HORIZONTAL);
    
    boxSizer5->Add(m_staticline2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    wxBoxSizer* bSizer3 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer2->Add(bSizer3, 0, wxALL|wxALIGN_LEFT, 5);
    
    m_staticText1 = new wxStaticText(this, wxID_ANY, _("Code navigation key:"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText1->SetToolTip(_("When using quick code navigation use this keys in combination with mouse click\nTo quickly go to implementation / declaration"));
    
    bSizer3->Add(m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText2 = new wxStaticText(this, wxID_ANY, _("Mouse Left Click +"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer3->Add(m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxCtrl = new wxCheckBox(this, wxID_ANY, _("Ctrl"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxCtrl->SetValue(false);
    
    bSizer3->Add(m_checkBoxCtrl, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxAlt = new wxCheckBox(this, wxID_ANY, _("Alt"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxAlt->SetValue(true);
    
    bSizer3->Add(m_checkBoxAlt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
}

EditorSettingsCommentsBase::~EditorSettingsCommentsBase()
{
}
