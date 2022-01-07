#include "Server.h"
#include "Utils.h"
#include <iostream>
using namespace std;

#define MAX_CONNECTIONS 5

Server::Server(int prt)
{
    port = prt;
    max_connections = MAX_CONNECTIONS;
}

bool Server::startServer()
{
    master_fd = Utils::setupServerSocket(port, max_connections);
    if(master_fd == -1)
    {
        cout << "Server start failed" << endl;
        return false;
    }
    cout << "Server started" << endl;
    return true;
}

void Server::acceptClient()
{
    int clientFd;

    bool clientConnectionStatus = Utils::acceptClient(master_fd, clientFd);
    if(clientConnectionStatus == false)
    {
        cout << "could not connect to client" << endl;
        return;
    }

    string msgFromClient, msgToClient;
    bool endSession = false;

    while(!endSession)
    {
        Utils::readMessage(clientFd, msgFromClient);
        cout << msgFromClient << endl;

        if(msgFromClient.compare("exit")==0)
        {
            endSession = true;
        }
        
        cin >> msgToClient;
        Utils::sendMessage(clientFd, msgToClient);
    }

}

