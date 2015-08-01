//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : editorsettingsdockingwidows.cpp
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

#include "editorsettingsdockingwidows.h"
#include "editor_config.h"
#include "frame.h"

EditorSettingsDockingWindows::EditorSettingsDockingWindows(wxWindow* parent)
    : EditorSettingsDockingWindowsBase(parent)
{
    OptionsConfigPtr options = EditorConfigST::Get()->GetOptions();

    m_checkBoxHideOutputPaneOnClick->SetValue(options->GetHideOutpuPaneOnUserClick());
    m_checkBoxHideOutputPaneNotIfBuild->SetValue(options->GetHideOutputPaneNotIfBuild());
    m_checkBoxHideOutputPaneNotIfSearch->SetValue(options->GetHideOutputPaneNotIfSearch());
    m_checkBoxHideOutputPaneNotIfReplace->SetValue(options->GetHideOutputPaneNotIfReplace());
    m_checkBoxHideOutputPaneNotIfReferences->SetValue(options->GetHideOutputPaneNotIfReferences());
    m_checkBoxHideOutputPaneNotIfOutput->SetValue(options->GetHideOutputPaneNotIfOutput());
    m_checkBoxHideOutputPaneNotIfTrace->SetValue(options->GetHideOutputPaneNotIfTrace());
    m_checkBoxHideOutputPaneNotIfTasks->SetValue(options->GetHideOutputPaneNotIfTasks());
    m_checkBoxHideOutputPaneNotIfBuildQ->SetValue(options->GetHideOutputPaneNotIfBuildQ());
    m_checkBoxHideOutputPaneNotIfCppCheck->SetValue(options->GetHideOutputPaneNotIfCppCheck());
    m_checkBoxHideOutputPaneNotIfSvn->SetValue(options->GetHideOutputPaneNotIfSvn());
    m_checkBoxHideOutputPaneNotIfCscope->SetValue(options->GetHideOutputPaneNotIfCscope());
    m_checkBoxHideOutputPaneNotIfGit->SetValue(options->GetHideOutputPaneNotIfGit());
    m_checkBoxHideOutputPaneNotIfDebug->SetValue(options->GetHideOutputPaneNotIfDebug());
    m_checkBoxHideOutputPaneNotIfMemCheck->SetValue(options->GetHideOutputPaneNotIfMemCheck());
    m_checkBoxFindBarAtBottom->SetValue(options->GetFindBarAtBottom());
    m_checkBoxShowReplaceBar->SetValue(options->GetShowReplaceBar());
    m_checkBoxDontFoldSearchResults->SetValue(options->GetDontAutoFoldResults());
    m_checkBoxShowDebugOnRun->SetValue(options->GetShowDebugOnRun());
    m_radioBoxHint->SetSelection(options->GetDockingStyle());
    m_checkBoxHideCaptions->SetValue(!options->IsShowDockingWindowCaption());
    m_checkBoxEnsureCaptionsVisible->SetValue(options->IsEnsureCaptionsVisible());
    m_checkBoxEditorTabsFollowsTheme->SetValue(options->IsTabColourMatchesTheme());
    m_checkBoxShowXButton->SetValue(options->IsTabHasXButton());
    m_checkBoxPanesTabsAtBottom->SetValue(!options->IsNonEditorTabsAtTop());
    m_checkBoxHideOutputPaneNotIfDebug->Connect(
        wxEVT_UPDATE_UI,
        wxUpdateUIEventHandler(EditorSettingsDockingWindows::OnHideOutputPaneNotIfDebugUI),
        NULL,
        this);
}

void EditorSettingsDockingWindows::Save(OptionsConfigPtr options)
{
    options->SetHideOutpuPaneOnUserClick(m_checkBoxHideOutputPaneOnClick->IsChecked());
    options->SetHideOutputPaneNotIfBuild(m_checkBoxHideOutputPaneNotIfBuild->IsChecked());
    options->SetHideOutputPaneNotIfSearch(m_checkBoxHideOutputPaneNotIfSearch->IsChecked());
    options->SetHideOutputPaneNotIfReplace(m_checkBoxHideOutputPaneNotIfReplace->IsChecked());
    options->SetHideOutputPaneNotIfReferences(m_checkBoxHideOutputPaneNotIfReferences->IsChecked());
    options->SetHideOutputPaneNotIfOutput(m_checkBoxHideOutputPaneNotIfOutput->IsChecked());
    options->SetHideOutputPaneNotIfTrace(m_checkBoxHideOutputPaneNotIfTrace->IsChecked());
    options->SetHideOutputPaneNotIfTasks(m_checkBoxHideOutputPaneNotIfTasks->IsChecked());
    options->SetHideOutputPaneNotIfBuildQ(m_checkBoxHideOutputPaneNotIfBuildQ->IsChecked());
    options->SetHideOutputPaneNotIfCppCheck(m_checkBoxHideOutputPaneNotIfCppCheck->IsChecked());
    options->SetHideOutputPaneNotIfSvn(m_checkBoxHideOutputPaneNotIfSvn->IsChecked());
    options->SetHideOutputPaneNotIfCscope(m_checkBoxHideOutputPaneNotIfCscope->IsChecked());
    options->SetHideOutputPaneNotIfGit(m_checkBoxHideOutputPaneNotIfGit->IsChecked());
    options->SetHideOutputPaneNotIfDebug(m_checkBoxHideOutputPaneNotIfDebug->IsChecked());
    options->SetHideOutputPaneNotIfMemCheck(m_checkBoxHideOutputPaneNotIfMemCheck->IsChecked());
    options->SetFindBarAtBottom(m_checkBoxFindBarAtBottom->IsChecked());
    options->SetShowReplaceBar(m_checkBoxShowReplaceBar->IsChecked());
    options->SetDontAutoFoldResults(m_checkBoxDontFoldSearchResults->IsChecked());
    options->SetShowDebugOnRun(m_checkBoxShowDebugOnRun->IsChecked());
    options->SetDockingStyle(m_radioBoxHint->GetSelection());
    options->SetShowDockingWindowCaption(!m_checkBoxHideCaptions->IsChecked());
    options->SetEnsureCaptionsVisible(m_checkBoxEnsureCaptionsVisible->IsChecked());
    options->SetTabColourMatchesTheme(m_checkBoxEditorTabsFollowsTheme->IsChecked());
    options->SetTabHasXButton(m_checkBoxShowXButton->IsChecked());
    options->SetNonEditorTabsAtTop(!m_checkBoxPanesTabsAtBottom->IsChecked());
    
    // Keep the quickreplacebar in sync
    clMainFrame::Get()->GetMainBook()->ShowQuickReplaceBar(m_checkBoxShowReplaceBar->IsChecked());
}

void EditorSettingsDockingWindows::OnHideOutputPaneNotIfDebugUI(wxUpdateUIEvent& event)
{
    event.Enable(m_checkBoxHideOutputPaneOnClick->IsChecked());
}

bool EditorSettingsDockingWindows::IsRestartRequired() { return false; }
void EditorSettingsDockingWindows::OnEnsureCaptionsVisibleUI(wxUpdateUIEvent& event)
{
#ifdef __WXMSW__
    event.Enable(m_checkBoxHideCaptions->IsChecked());
#else
    event.Enable(false);
    event.Check(false);
#endif
}
