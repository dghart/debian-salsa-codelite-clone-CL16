#ifndef IWORKSPACE_H
#define IWORKSPACE_H

#include <wx/string.h>
#include <wx/filename.h>
#include <list>
#include <wx/event.h>

/**
 * @class IWorkspace
 * @brief an interface representing the workspace concept of CodeLite
 * Each plugin that wants to implement a workspace must implement this interface
 */
class IWorkspace : public wxEvtHandler
{
protected:
    wxString m_workspaceType;

public:
    typedef std::list<IWorkspace*> List_t;

public:
    IWorkspace() {}
    virtual ~IWorkspace() {}

    /**
     * @brief set the workspace type
     * For example: "C++ Workspace", "PHP Workspace" etc
     */
    void SetWorkspaceType(const wxString& type) { this->m_workspaceType = type; }

    /**
     * @brief return the workspace name
     */
    const wxString& GetWorkspaceType() const { return m_workspaceType; }

    /**
     * @brief is this workspace support the build concept?
     * e.g. for C++ workspace, the answer is 'true', for PHP workspace, this will be 'false'
     */
    virtual bool IsBuildSupported() const = 0;

    /**
     * @brief is this workspace support the project concept?
     */
    virtual bool IsProjectSupported() const = 0;

    /**
     * @brief return the file masking for this workspace
     */
    virtual wxString GetFilesMask() const = 0;

    /**
     * @brief return the project name of a file.
     * If the workspace does not support projects, return an empty string
     * If the we could not match a project for the given filename, return empty string
     */
    virtual wxString GetProjectFromFile(const wxFileName& filename) const = 0;

    /**
     * @brief return a list of files for this workspace
     * @param files [output] list of files in absolute path
     */
    virtual void GetWorkspaceFiles(wxArrayString& files) const = 0;
    /**
     * @brief return list of files belonged to the prokect. If the workspace does not support
     * projects, do not modify 'files'
     * @param projectName the project name
     * @param files [output] list of files in absolute path
     */
    virtual void GetProjectFiles(const wxString& projectName, wxArrayString& files) const = 0;
};

#endif // IWORKSPACE_H