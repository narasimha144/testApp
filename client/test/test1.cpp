#include"Client.h"
using namespace std;

int main()
{
    Client c;
    
    c.createClient();
    c.connectToServer("127.0.0.1", 8080);

    return 0;
}
