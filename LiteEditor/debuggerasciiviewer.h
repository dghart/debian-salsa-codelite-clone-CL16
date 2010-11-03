#ifndef __debuggerasciiviewer__
#define __debuggerasciiviewer__

/**
@file
Subclass of DebuggerAsciiViewerBase, which is generated by wxFormBuilder.
*/

#include "debuggerasciiviewerbase.h"

class IDebugger;

/** Implementing DebuggerAsciiViewerBase */
class DebuggerAsciiViewer : public DebuggerAsciiViewerBase
{
	void OnClearView(wxCommandEvent &e);
	void OnEdit  (wxCommandEvent &e);
	void OnEditUI(wxUpdateUIEvent &e);

	bool IsFocused();
public:
	/** Constructor */
	DebuggerAsciiViewer( wxWindow* parent     );
	virtual ~DebuggerAsciiViewer();
	void UpdateView    (const wxString &expr, const wxString &value);
};

#endif // __debuggerasciiviewer__
