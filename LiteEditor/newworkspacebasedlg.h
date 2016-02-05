//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : newworkspacebasedlg.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: new_workspace_dlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_LITEEDITOR_NEW_WORKSPACE_DLG_BASE_CLASSES_H
#define CODELITE_LITEEDITOR_NEW_WORKSPACE_DLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class NewWorkspaceBase : public wxDialog
{
protected:
    wxPanel* m_panelWorkspace;
    wxStaticText* m_staticText1;
    wxTextCtrl* m_textCtrlWorkspaceName;
    wxStaticText* m_staticText3;
    wxComboBox* m_comboBoxPath;
    wxButton* m_buttonWorkspaceDirPicker;
    wxStaticText* m_staticTextWorkspaceFileName;
    wxCheckBox* m_checkBoxCreateSeparateDir;
    wxStdDialogButtonSizer* m_stdBtnSizer2;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:
    virtual void OnWorkspacePathUpdated(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWorkspaceDirPicker(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonCreate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText1() { return m_staticText1; }
    wxTextCtrl* GetTextCtrlWorkspaceName() { return m_textCtrlWorkspaceName; }
    wxStaticText* GetStaticText3() { return m_staticText3; }
    wxComboBox* GetComboBoxPath() { return m_comboBoxPath; }
    wxButton* GetButtonWorkspaceDirPicker() { return m_buttonWorkspaceDirPicker; }
    wxStaticText* GetStaticTextWorkspaceFileName() { return m_staticTextWorkspaceFileName; }
    wxCheckBox* GetCheckBoxCreateSeparateDir() { return m_checkBoxCreateSeparateDir; }
    wxPanel* GetPanelWorkspace() { return m_panelWorkspace; }
    NewWorkspaceBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New Workspace"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~NewWorkspaceBase();
};

#endif
