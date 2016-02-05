//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : abbreviationssettingsbase.h
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
// wxCrafter project file: abbreviationssettingsbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_ABBREVIATION_ABBREVIATIONSSETTINGSBASE_BASE_CLASSES_H
#define CODELITE_ABBREVIATION_ABBREVIATIONSSETTINGSBASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/bannerwindow.h>
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <map>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class AbbreviationsSettingsBase : public wxDialog
{
public:
    enum {
        ID_TOOL_DELETE = 1001,
        ID_TOOL_EXPORT = 1002,
        ID_TOOL_IMPORT = 1003,
        ID_TOOL_NEW = 1004,
    };
protected:
    wxBannerWindow* m_banner4;
    wxAuiToolBar* m_auibar9;
    wxListBox* m_listBoxAbbreviations;
    wxStaticText* m_staticText1;
    wxTextCtrl* m_textCtrlName;
    wxStyledTextCtrl* m_stc;
    wxCheckBox* m_checkBoxImmediateInsert;
    wxStaticLine* m_staticline1;
    wxStdDialogButtonSizer* m_stdBtnSizer24;
    wxButton* m_buttonSave;
    wxButton* m_buttonCancel;
    wxButton* m_buttonHelp;

protected:
    virtual void OnNew(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDeleteUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnDelete(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImport(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExport(wxCommandEvent& event) { event.Skip(); }
    virtual void OnItemSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMarkDirty(wxStyledTextEvent& event) { event.Skip(); }
    virtual void OnImmediateInsert(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSave(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnHelp(wxCommandEvent& event) { event.Skip(); }

public:
    wxBannerWindow* GetBanner4() { return m_banner4; }
    wxAuiToolBar* GetAuibar9() { return m_auibar9; }
    wxListBox* GetListBoxAbbreviations() { return m_listBoxAbbreviations; }
    wxStaticText* GetStaticText1() { return m_staticText1; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStyledTextCtrl* GetStc() { return m_stc; }
    wxCheckBox* GetCheckBoxImmediateInsert() { return m_checkBoxImmediateInsert; }
    wxStaticLine* GetStaticline1() { return m_staticline1; }
    AbbreviationsSettingsBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Abbreviations Settings..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~AbbreviationsSettingsBase();
};

#endif
