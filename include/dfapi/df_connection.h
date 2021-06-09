#pragma once

#include <string>

namespace df {

class Connection {
public:

  Connection();
  ~Connection();

  bool Connect(const std::string& address, int port, bool verbose = true);

  std::string connection_;
  int port_;

private:
    bool verbose_;                                   //!< Will print extra information to console if enabled.
};

}
