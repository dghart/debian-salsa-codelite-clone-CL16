/////////////////////////////////////////////////////////////////////////////
// Name:        wx/xrc/xh_aui.h
// Purpose:     XRC resource handler for wxAUI
// Author:      Andrea Zanellato, Steve Lamerton (wxAuiNotebook)
// Created:     2011-09-18
// Copyright:   (c) 2011 wxWidgets Team
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_XH_AUI_H_
#define _WX_XH_AUI_H_

#include "wx/xrc/xmlres.h"

#include "wx/vector.h"

class WXDLLIMPEXP_FWD_AUI wxAuiManager;
class WXDLLIMPEXP_FWD_AUI wxAuiNotebook;

class MyWxAuiManagerXmlHandler : public wxXmlResourceHandler
{
public:
    MyWxAuiManagerXmlHandler();
    virtual wxObject* DoCreateResource();
    virtual bool CanHandle(wxXmlNode* node);

    // Returns the wxAuiManager for the specified window
    wxAuiManager* GetAuiManager(wxWindow* managed) const;

private:
    // Used to UnInit() the wxAuiManager before destroying its managed window
    void OnManagedWindowClose(wxWindowDestroyEvent& event);

    typedef wxVector<wxAuiManager*> Managers;
    Managers m_managers; // all wxAuiManagers created in this handler

    wxAuiManager* m_manager; // Current wxAuiManager
    wxWindow* m_window;      // Current managed wxWindow
    wxAuiNotebook* m_notebook;

    bool m_mgrInside; // Are we handling a wxAuiManager or panes inside it?
    bool m_anbInside; // Are we handling a wxAuiNotebook or pages inside it?

    wxDECLARE_DYNAMIC_CLASS(MyWxAuiManagerXmlHandler);
};

#endif //_WX_XH_AUI_H_
