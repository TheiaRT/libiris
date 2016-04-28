#include <algorithm>
#include "tcp_server.h"

std::string reverse_request(const std::string req) {
    std::string rcopy = req;
    reverse(rcopy.begin(), rcopy.end());
    return rcopy;
}

int main() {
    TCPServer *server = new TCPServer(reverse_request);
    if (server->start("localhost", 8000) == false) {
        std::cerr << "Could not start server." << std::endl;
        return 1;
    }
    std::cerr << "Listening on localhost:8000..." << std::endl;
    while (1) {
        sleep(1);
    }
    return 0;
}
