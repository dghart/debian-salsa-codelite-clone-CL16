//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : setters_getters_dlg.h              
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
 #ifndef __setters_getters_dlg__
#define __setters_getters_dlg__

/**
@file
Subclass of SettersGettersBaseDlg, which is generated by wxFormBuilder.
@todo Add your event handlers directly to this file.
*/

#include "setters_getters_base_dlg.h"
#include "manager.h"
#include "ctags_manager.h"

/** Implementing SettersGettersBaseDlg */
class SettersGettersDlg : public SettersGettersBaseDlg
{
	std::vector<TagEntryPtr> m_members;
	wxFileName m_file;
	int m_lineno;
	std::map<wxString, TagEntryPtr> m_tagsMap;
	wxString m_code;

protected:
	void OnCheckStartWithUpperCase(wxCommandEvent &event);
	void OnCheckAll(wxCommandEvent &e);
	void OnUncheckAll(wxCommandEvent &e);
	
	wxString GenerateFunctions();
	wxString GenerateSetter(TagEntryPtr tag);
	wxString GenerateGetter(TagEntryPtr tag);
	void FormatName(wxString &name);
	void UpdatePreview();
	void GenerateGetters(wxString &code);
	void GenerateSetters(wxString &code);
	
public:
	/** Constructor */
	SettersGettersDlg(wxWindow* parent);
	const wxString &GetGenCode() const {return m_code;}
	void Init(const std::vector<TagEntryPtr> &tags, const wxFileName &file, int lineno);
};

#endif // __setters_getters_dlg__
