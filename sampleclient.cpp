#include <iostream>
#include "tcp_client.h"

int main() {
    std::string input;
    TCPClient client;
    while (getline(std::cin, input)) {
        if (client.connect("localhost", 8000) == false) {
            std::cerr << "Could not connect :(" << std::endl;
            return 1;
        }
        if (client.send_data(input) == false) {
            std::cerr << "Could not send data :(" << std::endl;
            return 2;
        }
        std::cout << client.receive() << std::endl;
    }
    return 0;
}
