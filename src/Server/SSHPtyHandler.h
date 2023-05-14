#pragma once
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/TCPServerConnection.h>
#include "Server/IServer.h"
#include "Server/SSH/SSHSession.h"

namespace DB
{

class SSHPtyHandler : public Poco::Net::TCPServerConnection
{
public:
    explicit SSHPtyHandler(IServer & server_, ssh::SSHSession && session_, const Poco::Net::StreamSocket & socket);
    void run() override;

private:
    IServer & server;
    Poco::Logger * log;
    ssh::SSHSession session;
};

}
