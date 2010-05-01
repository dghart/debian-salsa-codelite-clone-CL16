#ifndef __compilerswitchespage__
#define __compilerswitchespage__

/**
@file
Subclass of CompilerSwitchesBase, which is generated by wxFormBuilder.
*/

#include "compiler_pages.h"
#include "advanced_settings.h"
#include "compiler.h"

/** Implementing CompilerSwitchesBase */
class CompilerSwitchesPage : public CompilerSwitchesBase, public ICompilerSubPage
{
	wxString m_cmpname;
	wxString m_selSwitchName ;
	wxString m_selSwitchValue;
protected:
	// Handlers for CompilerSwitchesBase events.
	void OnItemActivated( wxListEvent& event );
	void OnItemSelected( wxListEvent& event );

	void EditSwitch();
	void InitSwitches();
	void AddSwitch(const wxString &name, const wxString &value, bool choose);
public:
	/** Constructor */
	CompilerSwitchesPage( wxWindow* parent, const wxString &cmpname );
	virtual void Save(CompilerPtr cmp);
};

#endif // __compilerswitchespage__
