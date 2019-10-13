//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: eosUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_EOS_EOSWIKI_EOSUI_BASE_CLASSES_H
#define _CODELITE_EOS_EOSWIKI_EOSUI_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class EOSProjectWizardBase : public wxDialog
{
protected:
    wxStaticText* m_staticText12;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_staticText16;
    wxDirPickerCtrl* m_dirPickerPath;
    wxStaticText* m_staticText26;
    wxDirPickerCtrl* m_dirPickerToolchainPath;
    wxCheckBox* m_checkBoxSeparateDir;
    wxStaticText* m_staticTextActualPath;
    wxStdDialogButtonSizer* m_stdBtnSizer4;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:
    virtual void OnNameUpdated(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPathChanged(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnCreateInSeparateDir(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText12() { return m_staticText12; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStaticText* GetStaticText16() { return m_staticText16; }
    wxDirPickerCtrl* GetDirPickerPath() { return m_dirPickerPath; }
    wxStaticText* GetStaticText26() { return m_staticText26; }
    wxDirPickerCtrl* GetDirPickerToolchainPath() { return m_dirPickerToolchainPath; }
    wxCheckBox* GetCheckBoxSeparateDir() { return m_checkBoxSeparateDir; }
    wxStaticText* GetStaticTextActualPath() { return m_staticTextActualPath; }
    EOSProjectWizardBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New EOS Project"),
                         const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, -1),
                         long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~EOSProjectWizardBase();
};

#endif
