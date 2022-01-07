#include <string>
using namespace std;

class Utils
{
    public:

        static int setupServerSocket(int port, int numOfConnections);

        static int createClientSocket();

        static bool connectClientToServer(int fd, string serverIp, int port);

        static bool acceptClient(int serverFd, int &clientFd);

        static bool closeSocket(int fd);

        static void sendMessage(int fd, string message);

        static void readMessage(int fd, string& message);
        
};