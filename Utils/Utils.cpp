#include "Utils.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define MAX 1024

bool Utils::closeSocket(int fd)
{
    cout << "closing socket " << fd << "...." << endl;
    close(fd);
    return true;
}

void Utils::sendMessage(int fd, string message)
{
    int len = message.length();
    send(fd, message.c_str(), len, 0);
}

void Utils::readMessage(int fd, string& message)
{
    char buffer[MAX]={0};
    int len = read(fd, buffer, MAX);

    message.assign(buffer, buffer+len);
}

int Utils::setupServerSocket(int port, int numOfConnections)
{
    int master_socket;

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(master_socket < 0)
    {
        cout << "Error!! Socket creation failed: " << errno << endl;
        return -1;
    }
    cout << "Socket creation successful" << endl;

    int enable = 1, ret;
    ret = setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)); 
    if (ret < 0)
    {
        cout << "setsockopt(SO_REUSEADDR) failed: " << errno << endl;
        if(master_socket >= 0)
        {
            closeSocket(master_socket);
        }
        return -1;
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(port);

    ret = bind(master_socket, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    if(ret < 0)
    {
        cout << "Error!! bind failed: " << errno << endl;
        if(master_socket >= 0)
        {
            closeSocket(master_socket);
        }
        return -1; 
    }
    cout << "Socket bounded to port: " << port << endl;

    ret = listen(master_socket, numOfConnections);
    if(ret < 0)
    {
        cout << "Error!! listen failed: " << errno << endl;
        if(master_socket >= 0) 
        {
            closeSocket(master_socket);
        }
        return -1;
    }

    cout << "Server socket fd : " << master_socket << " is ready to be used" << endl;

    return master_socket;
}

int Utils::createClientSocket()
{
    int sock;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        cout << "Error!! Socket creation failed: " << errno << endl;
        return -1;
    }

    return sock;
}

bool Utils::connectClientToServer(int fd, string serverIp, int port)
{
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(serverIp.c_str());
    serveraddr.sin_port = htons(port);

    int ret = connect(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if(ret < 0)
    {
        cout << "Error!! connect failed: " << errno << endl;
        return false;
    }

    return true;
}


bool Utils::acceptClient(int serverFd, int &clientFd)
{
    clientFd = accept(serverFd, NULL, NULL);

    if(clientFd < 0)
    {
        cout << "Error!! accept failed: " << errno << endl;
        return false;
    }

    cout << "Server socket fd: " << serverFd << " and Client Socket fd: " << clientFd << endl;
    return true;
}

bool Utils::acceptIncomingClients(int serverFd, int &clientFd)
{
    fd_set readfds;
    int client_socket[30], max_clients=30;
    
    int sd, max_sd, activity;
    
    cout << "Waiting for connections..." << endl;
    
    while(true)
    {
        FD_ZERO(&readfds);

        FD_SET(serverFd, &readfds);
        max_sd = serverFd;

        for(int i=0; i< max_clients; i++)
        {
            sd = client_socket[i];
            
            if(sd > 0)
            {
                FD_SET(sd, &readfds);
            }

            if(sd > max_sd)
            {
                max_sd = sd;
            }
        }

        activity = select(max_sd+1, &readfds, NULL, NULL, NULL);

        if((activity < 0) && (errno != EINTR))
        {
            cout << "Error in select" << endl;
            return false;
        }

        if(FD_ISSET(serverFd, &readfds))
        {
            int clientFd;
            if(!acceptClient(serverFd, clientFd))
            {
                return false;
            }

            for(int i=0;i < max_clients; i++)
            {
                if(client_socket[i] == 0)
                {
                    client_socket[i] = clientFd;
                    cout << "Adding to list of sockets as " << i << endl;
                }
            }
        }

        for(int i=0; i<max_clients; i++)
        {
            sd = client_socket[i];
            if(FD_ISSET(sd, &readfds))
            {
                
            }
        }
    }
}

