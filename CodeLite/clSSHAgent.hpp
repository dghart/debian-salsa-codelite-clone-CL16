#ifndef CLSSHAGENT_HPP
#define CLSSHAGENT_HPP

#include "codelite_exports.h"
#include <wx/sharedptr.h>

class IProcess;
class WXDLLIMPEXP_CL clSSHAgent
{
private:
    IProcess* m_process = nullptr;

protected:
    void Start();
    void Stop();

public:
    typedef wxSharedPtr<clSSHAgent> Ptr_t;

public:
    clSSHAgent();
    virtual ~clSSHAgent();
};

#endif // CLSSHAGENT_HPP
