#include"Server.h"

int main()
{
    int PORT = 8080;
    
    Server srv = *new Server(PORT);
    srv.startServer();
    
    while(1)
    {
        srv.acceptClient();
    }

    return 0;
}