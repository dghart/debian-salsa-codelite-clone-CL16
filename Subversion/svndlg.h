//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : svndlg.h
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
 #ifndef __svndlg__
#define __svndlg__

/**
@file
Subclass of SvnBaseDlg, which is generated by wxFormBuilder.
*/

#include "svnbasedlg.h"

class IManager;

/** Implementing SvnBaseDlg */
class SvnDlg : public SvnBaseDlg
{
	wxArrayString  m_files;
	IManager      *m_manager;

private:
	void OnLastCommitMsgSelected(wxCommandEvent &e);
	void OnButtonOK             (wxCommandEvent &e);
	void OnItemSelected         (wxCommandEvent &e);
public:
	/** Constructor */
	SvnDlg( wxWindow* parent, const wxArrayString &files, IManager *manager );
	virtual ~SvnDlg();
	wxString      GetLogMessage() const ;
	void          SetLogMessage(const wxString &message);
	wxArrayString GetFiles     () const;
};

#endif // __svndlg__
