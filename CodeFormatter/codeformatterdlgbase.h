//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : codeformatterdlgbase.h
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
// wxCrafter project file: codeformatterdlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_CODEFORMATTER_CODEFORMATTERDLG_BASE_CLASSES_H
#define CODELITE_CODEFORMATTER_CODEFORMATTERDLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/treebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/splitter.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif
#include "formatoptions.h"
#include "PHPFormatterBuffer.h"

class CodeFormatterBaseDlg : public wxDialog
{
protected:
    wxTreebook* m_treebook;
    wxPanel* m_panel133;
    wxCheckBox* m_checkBoxFormatOnSave;
    wxStaticText* m_staticText115;
    wxChoice* m_choiceCxxEngine;
    wxStaticText* m_staticText198;
    wxChoice* m_choicePhpFormatter;
    wxPanel* m_panelCxx;
    wxPanel* m_panelAstyle;
    wxSplitterWindow* m_splitter145;
    wxPanel* m_splitterPage149;
    wxPropertyGridManager* m_pgMgrAstyle;
    wxPGProperty* m_pgPropAstyleOptions;
    wxPGProperty* m_pgPropPreDefinedStyles;
    wxPGProperty* m_pgPropBrackets;
    wxPGProperty* m_pgPropIndentation;
    wxPGProperty* m_pgPropFormatting;
    wxStaticText* m_staticText59;
    wxStaticText* m_staticText3;
    wxTextCtrl* m_textCtrlUserFlags;
    wxPanel* m_splitterPage153;
    wxStyledTextCtrl* m_textCtrlPreview;
    wxPanel* m_panelClang;
    wxSplitterWindow* m_splitter165;
    wxPanel* m_splitterPage169;
    wxPropertyGridManager* m_pgMgrClang;
    wxPGProperty* m_pgPropClangFormat;
    wxPGProperty* m_pgPropClangFormatExePath;
    wxPGProperty* m_pgPropColumnLimit;
    wxPGProperty* m_pgPropClangBraceBreakStyle;
    wxPGProperty* m_pgPropClangFormatStyle;
    wxPGProperty* m_pgPropClangFormattingOptions;
    wxPanel* m_splitterPage173;
    wxStyledTextCtrl* m_textCtrlPreview_Clang;
    wxPanel* m_panelPHP;
    wxPanel* m_panelBuiltIn;
    wxSplitterWindow* m_splitter119;
    wxPanel* m_splitterPage123;
    wxPropertyGridManager* m_pgMgrPhp;
    wxPGProperty* m_pgPropPhpFormatter;
    wxPGProperty* m_pgPropPhpFormatterOptions;
    wxPanel* m_splitterPage127;
    wxStyledTextCtrl* m_stcPhpPreview;
    wxPanel* m_panel185;
    wxStaticText* m_staticText192;
    wxFilePickerCtrl* m_filePickerPhpExec;
    wxStaticText* m_staticText202;
    wxFilePickerCtrl* m_filePickerPHPCsFixerPhar;
    wxStaticText* m_staticText217;
    wxStyledTextCtrl* m_stc;
    wxStyledTextCtrl* m_stcFixerPreview;
    wxStdDialogButtonSizer* m_stdBtnSizer30;
    wxButton* m_buttonOK;
    wxButton* m_buttonApply;
    wxButton* m_buttonCancel;
    wxButton* m_buttonHelp;

protected:
    virtual void OnFormatOnSave(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChoicecxxengineChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChoicephpformatterChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPgmgrastylePgChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void OnCustomAstyleFlags(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPgmgrclangPgChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void OnPgmgrphpPgChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void OnPhpFileSelected(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnPharFileSelected(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnPHPCSFixerOptionsUpdated(wxStyledTextEvent& event) { event.Skip(); }
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }
    virtual void OnApplyUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnApply(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHelp(wxCommandEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBoxFormatOnSave() { return m_checkBoxFormatOnSave; }
    wxStaticText* GetStaticText115() { return m_staticText115; }
    wxChoice* GetChoiceCxxEngine() { return m_choiceCxxEngine; }
    wxStaticText* GetStaticText198() { return m_staticText198; }
    wxChoice* GetChoicePhpFormatter() { return m_choicePhpFormatter; }
    wxPanel* GetPanel133() { return m_panel133; }
    wxPropertyGridManager* GetPgMgrAstyle() { return m_pgMgrAstyle; }
    wxStaticText* GetStaticText59() { return m_staticText59; }
    wxStaticText* GetStaticText3() { return m_staticText3; }
    wxTextCtrl* GetTextCtrlUserFlags() { return m_textCtrlUserFlags; }
    wxPanel* GetSplitterPage149() { return m_splitterPage149; }
    wxStyledTextCtrl* GetTextCtrlPreview() { return m_textCtrlPreview; }
    wxPanel* GetSplitterPage153() { return m_splitterPage153; }
    wxSplitterWindow* GetSplitter145() { return m_splitter145; }
    wxPanel* GetPanelAstyle() { return m_panelAstyle; }
    wxPropertyGridManager* GetPgMgrClang() { return m_pgMgrClang; }
    wxPanel* GetSplitterPage169() { return m_splitterPage169; }
    wxStyledTextCtrl* GetTextCtrlPreview_Clang() { return m_textCtrlPreview_Clang; }
    wxPanel* GetSplitterPage173() { return m_splitterPage173; }
    wxSplitterWindow* GetSplitter165() { return m_splitter165; }
    wxPanel* GetPanelClang() { return m_panelClang; }
    wxPanel* GetPanelCxx() { return m_panelCxx; }
    wxPropertyGridManager* GetPgMgrPhp() { return m_pgMgrPhp; }
    wxPanel* GetSplitterPage123() { return m_splitterPage123; }
    wxStyledTextCtrl* GetStcPhpPreview() { return m_stcPhpPreview; }
    wxPanel* GetSplitterPage127() { return m_splitterPage127; }
    wxSplitterWindow* GetSplitter119() { return m_splitter119; }
    wxPanel* GetPanelBuiltIn() { return m_panelBuiltIn; }
    wxStaticText* GetStaticText192() { return m_staticText192; }
    wxFilePickerCtrl* GetFilePickerPhpExec() { return m_filePickerPhpExec; }
    wxStaticText* GetStaticText202() { return m_staticText202; }
    wxFilePickerCtrl* GetFilePickerPHPCsFixerPhar() { return m_filePickerPHPCsFixerPhar; }
    wxStaticText* GetStaticText217() { return m_staticText217; }
    wxStyledTextCtrl* GetStc() { return m_stc; }
    wxStyledTextCtrl* GetStcFixerPreview() { return m_stcFixerPreview; }
    wxPanel* GetPanel185() { return m_panel185; }
    wxPanel* GetPanelPHP() { return m_panelPHP; }
    wxTreebook* GetTreebook() { return m_treebook; }
    CodeFormatterBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Source Code Formatter Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CodeFormatterBaseDlg();
};

#endif
