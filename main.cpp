#include "connection.h"
#include <Poco/Event.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/NumberParser.h>
#include <iostream>

Poco::Event terminator;

int
main(int argc, char** argv)
{
    if (argc != 2)
        return -1;

    auto port = Poco::NumberParser::parse(argv[1]);

    try {
        Poco::Net::TCPServer server(new Connection::Factory(), port);
        server.start();

        terminator.wait();
    } catch (Poco::Exception& e) {
        std::cerr << "Server error:" << e.displayText() << std::endl;
    }

    return 0;
}