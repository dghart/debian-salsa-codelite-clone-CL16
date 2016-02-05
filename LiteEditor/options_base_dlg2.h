//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : options_base_dlg2.h
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
// wxCrafter project file: optionsdialogbase2.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_LITEEDITOR_OPTIONSDIALOGBASE2_BASE_CLASSES_H
#define CODELITE_LITEEDITOR_OPTIONSDIALOGBASE2_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/treebook.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class OptionsBaseDlg2 : public wxDialog
{
protected:
    wxTreebook* m_treeBook;
    wxButton* m_okButton;
    wxButton* m_cancelButton;
    wxButton* m_applyButton;

protected:
    virtual void OnActivate(wxActivateEvent& event) { event.Skip(); }
    virtual void OnInitDialog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonApply(wxCommandEvent& event) { event.Skip(); }

public:
    wxTreebook* GetTreeBook() { return m_treeBook; }
    wxButton* GetOkButton() { return m_okButton; }
    wxButton* GetCancelButton() { return m_cancelButton; }
    wxButton* GetApplyButton() { return m_applyButton; }
    OptionsBaseDlg2(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Editor Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~OptionsBaseDlg2();
};

#endif
