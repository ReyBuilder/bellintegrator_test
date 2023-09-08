#ifndef __CONNECTION_H
#define __CONNECTION_H

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>

class Connection : public Poco::Net::TCPServerConnection
{
  public:
    Connection(const Poco::Net::StreamSocket& socket)
      : Poco::Net::TCPServerConnection(socket){};

    void run();

    typedef Poco::Net::TCPServerConnectionFactoryImpl<Connection> Factory;

  private:
    static const char* hello_message;
};

#endif