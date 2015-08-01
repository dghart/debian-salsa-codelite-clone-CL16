//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: nameanddescdlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_PLUGIN_NAMEANDDESCDLG_BASE_CLASSES_H
#define CODELITE_PLUGIN_NAMEANDDESCDLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif
#include "codelite_exports.h"

class WXDLLIMPEXP_SDK NameAndDescBaseDlg : public wxDialog
{
protected:
    wxBoxSizer* bSizer1;
    wxFlexGridSizer* fgSizer1;
    wxStaticText* m_staticText3;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_staticText4;
    wxComboBox* m_choiceType;
    wxBoxSizer* bSizer3;
    wxStaticText* m_staticText2;
    wxTextCtrl* m_textCtrlDescription;
    wxStdDialogButtonSizer* m_stdBtnSizer2;
    wxButton* m_buttonOK;
    wxButton* m_button6;

protected:

public:
    wxStaticText* GetStaticText3() { return m_staticText3; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStaticText* GetStaticText4() { return m_staticText4; }
    wxComboBox* GetChoiceType() { return m_choiceType; }
    wxStaticText* GetStaticText2() { return m_staticText2; }
    wxTextCtrl* GetTextCtrlDescription() { return m_textCtrlDescription; }
    NameAndDescBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Save Project As Template"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~NameAndDescBaseDlg();
};

#endif
