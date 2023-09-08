#include "connection.h"
#include <iostream>
#include <string>

const char* Connection::hello_message =
  "Welcome to POCO TCP server. Enter you string:";

void
Connection::run()
{
    auto s = socket();

    s.sendBytes(hello_message, strlen(hello_message));

    while (true) {
        try {
            char buf[255];

            int res = s.receiveBytes(buf, sizeof(buf));
            if (res == 0)
                break;

            for (int i = 0; i < res / 2; i++) {
                int j = res - 1 - i;
                char tmp = buf[i];

                buf[i] = buf[j];
                buf[j] = tmp;
            }
            s.sendBytes(buf, res);
        } catch (Poco::Exception& e) {
            std::cerr << "Connection error: " << e.displayText() << std::endl;
            break;
        }
    }
}