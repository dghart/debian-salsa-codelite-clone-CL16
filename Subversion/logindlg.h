//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : logindlg.h              
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
 #ifndef __logindlg__
#define __logindlg__

/**
@file
Subclass of LoginBaseDialog, which is generated by wxFormBuilder.
*/

#include "logindlgbase.h"

/** Implementing LoginBaseDialog */
class LoginDialog : public LoginBaseDialog
{
public:
	/** Constructor */
	LoginDialog( wxWindow* parent );
	wxString GetUsername() const {return m_textCtrlUsername->GetValue();}
	wxString GetPassword() const {return m_textCtrlPassword->GetValue();}
};

#endif // __logindlg__
