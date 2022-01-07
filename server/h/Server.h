class Server
{
    public:

        int master_fd;
        int port, max_connections;

        Server(int prt);

        bool startServer();
        void acceptClient();
};