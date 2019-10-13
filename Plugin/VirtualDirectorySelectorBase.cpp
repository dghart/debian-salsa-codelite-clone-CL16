//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: VirtualDirectorySelectorBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "VirtualDirectorySelectorBase.h"
#include "codelite_exports.h"

// Declare the bitmap loading function
extern void wxC168BInitBitmapResources();

static bool bBitmapLoaded = false;

VirtualDirectorySelectorDlgBaseClass::VirtualDirectorySelectorDlgBaseClass(wxWindow* parent, wxWindowID id,
                                                                           const wxString& title, const wxPoint& pos,
                                                                           const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC168BInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);

    m_staticText1 = new wxStaticText(this, wxID_ANY, _("Select Virtual Folder:"), wxDefaultPosition,
                                     wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    bSizer1->Add(m_staticText1, 0, wxALL | wxEXPAND | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_treeCtrl = new clThemedTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(300, 200)),
                                      wxTR_DEFAULT_STYLE | wxTR_SINGLE);
    m_treeCtrl->SetFocus();

    bSizer1->Add(m_treeCtrl, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* sbSizer1 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("")), wxVERTICAL);

    bSizer1->Add(sbSizer1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextPreview =
        new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    sbSizer1->Add(m_staticTextPreview, 0, wxEXPAND | wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    bSizer1->Add(bSizer2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOk->SetDefault();

    bSizer2->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonCancel =
        new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    bSizer2->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

    m_button1 = new wxButton(this, wxID_NEW, _("New..."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button1->SetToolTip(_("Create new virtual folder..."));

    bSizer2->Add(m_button1, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("VirtualDirectorySelectorDlgBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_SEL_CHANGED,
                        wxTreeEventHandler(VirtualDirectorySelectorDlgBaseClass::OnItemSelected), NULL, this);
    m_buttonOk->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonOK), NULL, this);
    m_buttonOk->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonOkUI),
                        NULL, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                            wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonCancel), NULL, this);
    m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                       wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnNewVD), NULL, this);
    m_button1->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(VirtualDirectorySelectorDlgBaseClass::OnNewVDUI), NULL,
                       this);
}

VirtualDirectorySelectorDlgBaseClass::~VirtualDirectorySelectorDlgBaseClass()
{
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_SEL_CHANGED,
                           wxTreeEventHandler(VirtualDirectorySelectorDlgBaseClass::OnItemSelected), NULL, this);
    m_buttonOk->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                           wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonOK), NULL, this);
    m_buttonOk->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonOkUI),
                           NULL, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnButtonCancel), NULL, this);
    m_button1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                          wxCommandEventHandler(VirtualDirectorySelectorDlgBaseClass::OnNewVD), NULL, this);
    m_button1->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(VirtualDirectorySelectorDlgBaseClass::OnNewVDUI),
                          NULL, this);
}
