//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : newinheritancedlg.cpp
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
#include "newinheritancedlg.h"
#include "windowattrmanager.h"
#include "open_type_dlg.h"
#include "imanager.h"

NewIneritanceDlg::NewIneritanceDlg( wxWindow* parent, IManager *mgr, const wxString &parentName, const wxString &access )
: NewIneritanceBaseDlg( parent, wxID_ANY, wxT("New Inheritance"))
, m_mgr(mgr)
{
	//by default select 0
	m_choiceAccess->Select(0);
	if(access.IsEmpty() == false){
		m_choiceAccess->SetStringSelection(access);
	}
	m_textCtrlInhertiance->SetValue(parentName);
	Centre();

	WindowAttrManager::Load(this, wxT("NewIneritanceDlg"), m_mgr->GetConfigTool());
}

NewIneritanceDlg::~NewIneritanceDlg()
{
	WindowAttrManager::Save(this, wxT("NewIneritanceDlg"), m_mgr->GetConfigTool());
}

void NewIneritanceDlg::OnButtonMore( wxCommandEvent& event )
{
	OpenTypeDlg *dlg = new OpenTypeDlg(this, m_mgr->GetTagsManager());
	if(dlg->ShowModal() == wxID_OK){
		wxString parentName;
		if(	dlg->GetSelectedTag()->GetScope().IsEmpty() == false &&
			dlg->GetSelectedTag()->GetScope() != wxT("<global>"))
		{
			parentName << dlg->GetSelectedTag()->GetScope() << wxT("::");
		}
		parentName << dlg->GetSelectedTag()->GetName();
		m_textCtrlInhertiance->SetValue(parentName);

		m_fileName = dlg->GetSelectedTag()->GetFile();
	}
	dlg->Destroy();
}
