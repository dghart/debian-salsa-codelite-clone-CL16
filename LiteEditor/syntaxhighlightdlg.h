//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : syntaxhighlightdlg.h              
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

#ifndef __syntaxhighlightdlg__
#define __syntaxhighlightdlg__

/**
@file
Subclass of SyntaxHighlightBaseDlg, which is generated by wxFormBuilder.
*/

#include "syntaxhighlightbasedlg.h"
#include "lexer_configuration.h"
class wxChoice;
class wxNotebook;

/** Implementing SyntaxHighlightBaseDlg */
class SyntaxHighlightDlg : public SyntaxHighlightBaseDlg
{
	wxChoice* m_themes;
	wxNotebook *m_lexersBook;
	wxString m_startingTheme;
	
protected:
	// Handlers for SyntaxHighlightBaseDlg events.
	void OnButtonOK( wxCommandEvent& event );
	void OnButtonCancel( wxCommandEvent& event );
	void OnButtonApply( wxCommandEvent& event );
	void OnThemeChanged(wxCommandEvent& event);
	void OnRestoreDefaults(wxCommandEvent &e);
	
	wxPanel *CreateSyntaxHighlightPage();
	void LoadLexers(const wxString& theme);	
	wxPanel *CreateLexerPage(wxWindow *parent, LexerConfPtr lexer);
	void SaveChanges();
	
public:
	/** Constructor */
	SyntaxHighlightDlg( wxWindow* parent );
	virtual ~SyntaxHighlightDlg();
	
};

#endif // __syntaxhighlightdlg__
