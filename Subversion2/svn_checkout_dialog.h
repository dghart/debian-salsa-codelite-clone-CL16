#ifndef __svn_checkout_dialog__
#define __svn_checkout_dialog__

/**
@file
Subclass of SvnCheckoutDialogBase, which is generated by wxFormBuilder.
*/

#include "subversion2_ui.h"
class Subversion2;

/** Implementing SvnCheckoutDialogBase */
class SvnCheckoutDialog : public SvnCheckoutDialogBase
{
	Subversion2 *m_plugin;
protected:
	// Handlers for SvnCheckoutDialogBase events.
	void OnBrowseDirectory      ( wxCommandEvent  &event );
	void OnOkUI                 ( wxUpdateUIEvent &event );

	virtual void OnOK( wxCommandEvent& event );

public:
	/** Constructor */
	SvnCheckoutDialog( wxWindow* parent, Subversion2 *plugin );
	virtual ~SvnCheckoutDialog();

	wxString GetURL();
	wxString GetTargetDir();
};

#endif // __svn_checkout_dialog__
