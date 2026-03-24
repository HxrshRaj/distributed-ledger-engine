#include "network.h"
#include <iostream>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

void Network::startServer(int port) {
    std::cout << "Starting server on port " << port << std::endl;

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
#endif

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "Server listening..." << std::endl;

    int addrlen = sizeof(address);
    int new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

    char buffer[1024] = {0};
    recv(new_socket, buffer, 1024, 0);

    std::cout << "Received transaction: " << buffer << std::endl;

#ifdef _WIN32
    closesocket(new_socket);
    WSACleanup();
#else
    close(new_socket);
#endif
}