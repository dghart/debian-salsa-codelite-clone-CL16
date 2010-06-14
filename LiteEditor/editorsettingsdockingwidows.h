#ifndef __editorsettingsdockingwidows__
#define __editorsettingsdockingwidows__

/**
@file
Subclass of EditorSettingsDockingWindowsBase, which is generated by wxFormBuilder.
*/

#include "editorsettingsdockingwindowsbase.h"
#include "treebooknodebase.h"
#include "optionsconfig.h"

/** Implementing EditorSettingsDockingWindowsBase */
class EditorSettingsDockingWindows
: public EditorSettingsDockingWindowsBase
, public TreeBookNode<EditorSettingsDockingWindows>
{
	void OnHideOutputPaneNotIfDebugUI(wxUpdateUIEvent& event);
public:
	/** Constructor */
	EditorSettingsDockingWindows( wxWindow* parent );
	virtual void Save(OptionsConfigPtr options);
};

#endif // __editorsettingsdockingwidows__
