//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: editor_options_terminal.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editorsettings_terminal_base.h"

// Declare the bitmap loading function
extern void wxC575EInitBitmapResources();

static bool bBitmapLoaded = false;

EditorSettingsTerminalBase::EditorSettingsTerminalBase(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                                                       const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC575EInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);

    m_staticText2 = new wxStaticText(this, wxID_ANY, _("Select the terminal to use:"), wxDefaultPosition,
                                     wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    bSizer1->Add(m_staticText2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_choiceTerminalsArr;
    m_choiceTerminals =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTerminalsArr, 0);

    bSizer1->Add(m_choiceTerminals, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("EditorSettingsTerminalBase"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    // Connect events
    m_staticText2->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsTerminalBase::OnUseCodeLiteTerminalUI),
                           NULL, this);
}

EditorSettingsTerminalBase::~EditorSettingsTerminalBase()
{
    m_staticText2->Disconnect(wxEVT_UPDATE_UI,
                              wxUpdateUIEventHandler(EditorSettingsTerminalBase::OnUseCodeLiteTerminalUI), NULL, this);
}
