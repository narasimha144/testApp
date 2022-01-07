#include "Client.h"
#include "Utils.h"
#include <iostream>
using namespace std;

bool Client::createClient()
{
    fd = Utils::createClientSocket();
    if(fd == -1)
    {
        cout << "Client creation error" << endl;
        return false;
    }
    cout << "client created" << endl;
    return true;
}

void Client::connectToServer(string serverIp, int port)
{
    connectionStatus =  Utils::connectClientToServer(fd, serverIp, port);
    if(connectionStatus == false)
    {
        cout << "Client connection to server error" << endl;
        return;
    }

    string msgFromServer, msgToServer;
    bool endSession = false;

    while(!endSession)
    {
        cin >> msgToServer;
        Utils::sendMessage(fd, msgToServer);
        
        Utils::readMessage(fd, msgFromServer);
        cout << msgFromServer << endl;

        if(msgFromServer.compare("exiting")==0)
        {
            endSession = true;
        }
    }
}