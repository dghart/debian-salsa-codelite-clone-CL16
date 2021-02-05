#include "SSHRemoteProcess.hpp"
#include "clSSHChannel.hpp"
#if USE_SFTP
#include "cl_command_event.h"
#include "file_logger.h"
#include "processreaderthread.h"
#include <wx/utils.h>

bool do_ssh_write(clSSHChannel::Ptr_t channel, const wxString& buffer)
{
    try {
        if(!channel->IsInteractive()) {
            channel->Execute(buffer);
        } else {
            channel->Write(buffer);
        }
    } catch(clException& e) {
        clERROR() << e.What();
        return false;
    }
    return true;
}

SSHRemoteProcess::SSHRemoteProcess(wxEvtHandler* owner, clSSH::Ptr_t ssh, clSSHChannel::eChannelType type)
    : IProcess(NULL)
    , m_owner(owner)
{
    m_ssh = ssh;
    m_channel.reset(new clSSHChannel(ssh, type, this));
    m_channel->Open(); // may throw
    Bind(wxEVT_SSH_CHANNEL_PTY, &SSHRemoteProcess::OnPty, this);
    Bind(wxEVT_SSH_CHANNEL_WRITE_ERROR, &SSHRemoteProcess::OnError, this);
    Bind(wxEVT_SSH_CHANNEL_READ_ERROR, &SSHRemoteProcess::OnError, this);
    Bind(wxEVT_SSH_CHANNEL_CLOSED, &SSHRemoteProcess::OnTerminate, this);
    Bind(wxEVT_SSH_CHANNEL_READ_OUTPUT, &SSHRemoteProcess::OnOutput, this);
}

SSHRemoteProcess::~SSHRemoteProcess() { Cleanup(); }

void SSHRemoteProcess::Cleanup()
{
    try {
        if(m_channel) {
            m_channel->SendSignal(wxSIGTERM);
            m_channel->Close();
        }
        m_channel.reset(nullptr);
        m_ssh.reset(nullptr);
    } catch(clException& e) {
        clWARNING() << "SSHRemoteProcess::Detach:" << e.What();
    }
}

void SSHRemoteProcess::Detach()
{
    if(m_channel) {
        // this does nothing
        m_channel->Detach();
    }
}

bool SSHRemoteProcess::IsAlive() { return m_channel->IsOpen(); }

bool SSHRemoteProcess::Read(wxString& buff, wxString& buffErr)
{
    wxUnusedVar(buff);
    wxUnusedVar(buffErr);
    return false;
}

void SSHRemoteProcess::Terminate()
{
    if(m_channel) {
        m_channel->Close();
        m_channel.reset();
    }
    if(m_ssh) {
        m_ssh.reset(nullptr);
    }
    clProcessEvent e(wxEVT_ASYNC_PROCESS_TERMINATED);
    GetOwner()->AddPendingEvent(e);
}

bool SSHRemoteProcess::Write(const std::string& buff) { return do_ssh_write(m_channel, buff); }

bool SSHRemoteProcess::Write(const wxString& buff) { return do_ssh_write(m_channel, buff); }

bool SSHRemoteProcess::WriteRaw(const std::string& buff) { return do_ssh_write(m_channel, buff); }

bool SSHRemoteProcess::WriteRaw(const wxString& buff) { return do_ssh_write(m_channel, buff); }

bool SSHRemoteProcess::WriteToConsole(const wxString& buff) { return do_ssh_write(m_channel, buff); }

IProcess* SSHRemoteProcess::Create(wxEvtHandler* owner, clSSH::Ptr_t ssh, const wxString& command, bool interactive)
{
    try {
        SSHRemoteProcess* process = new SSHRemoteProcess(
            owner, ssh, interactive ? clSSHChannel::kInterativeMode : clSSHChannel::kRemoteCommand);
        if(!command.IsEmpty()) {
            process->Write(command);
        }
        return process;
    } catch(clException& e) {
        return NULL;
    }
}

IProcess* SSHRemoteProcess::Create(wxEvtHandler* owner, const SSHAccountInfo& account, const wxString& command,
                                   bool interactive)
{
    try {
        clSSH::Ptr_t ssh(new clSSH());
        // Establish SSH connection and launch the build
        ssh->SetUsername(account.GetUsername());
        ssh->SetPassword(account.GetPassword());
        ssh->SetHost(account.GetHost());
        ssh->SetPort(account.GetPort());
        ssh->Connect();
        ssh->Login();

        SSHRemoteProcess* process = new SSHRemoteProcess(
            owner, ssh, interactive ? clSSHChannel::kInterativeMode : clSSHChannel::kRemoteCommand);
        if(!command.IsEmpty()) {
            process->Write(command);
        }
        return process;
    } catch(clException& e) {
        clERROR() << "Failed to start remote process." << e.What() << clEndl;
        return NULL;
    }
}

void SSHRemoteProcess::OnError(clCommandEvent& event)
{
    wxString msg = event.GetString(); // contains the error message
    clDEBUG() << "ssh error:" << msg;
    // Convert it to
    Terminate();
}

void SSHRemoteProcess::OnTerminate(clCommandEvent& event) { Terminate(); }

void SSHRemoteProcess::OnOutput(clCommandEvent& event)
{
    clProcessEvent e(wxEVT_ASYNC_PROCESS_OUTPUT);
    e.SetOutput(event.GetString());
    e.SetEventObject(this);
    GetOwner()->AddPendingEvent(e);
}

void SSHRemoteProcess::OnPty(clCommandEvent& event) { SetPty(event.GetString()); }

void SSHRemoteProcess::Signal(wxSignal sig)
{
    try {
        m_channel->SendSignal(sig);
    } catch(clException& e) {
        clWARNING() << "SSHRemoteProcess::Signal():" << e.What();
    }
}

#endif
