#include "dfapi/df_connection.h"

#include <iostream>

namespace df {

Connection::Connection() :
    connection_(""),
    port_(0),
    verbose_(false) {}

bool Connection::Connect(const std::string& address, int port, bool verbose) {
    verbose_ = verbose;
    connection_ = address;
    port_ = port;

    if (verbose_) {
        std::cout << "Connected..." << std::endl;
    }

    return true;
}

Connection::~Connection() {
    //Disconnect();
}
}
