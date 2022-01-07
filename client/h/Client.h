#include<string>
class Client
{
    public:

        int fd;
        bool connectionStatus;

        bool createClient();
        void connectToServer(std::string serverIp, int port);
};