#include "bhs_PCDataServer.h"

/**
 * @brief Constructor.
 */
bhs_PCDataServer::bhs_PCDataServer(void)
: mbServerReady(false)
, mConnectedSocket(0)
{
        mExternalUserSem = semBCreate(SEM_Q_FIFO,SEM_FULL);
        mServerReadySem = semBCreate(SEM_Q_FIFO,SEM_FULL);
        mCurrentConnectionDone = semBCreate(SEM_Q_FIFO,SEM_EMPTY);
        taskSpawn ("BHS_PCDataServer", 101, 0, 20000, (FUNCPTR)bhs_PCDataServer::ServerSocketTask,(int)this,0,0,0,0,0,0,0,0,0);
}

/**
 * @brief Destructor.
 * Stop serving images and destroy this class.
 */
bhs_PCDataServer::~bhs_PCDataServer()
{

}

void bhs_PCDataServer::xmitRawData(int anHeader,int anLen,char* apData)
{
    if (mbServerReady)
    {
        semTake(mExternalUserSem,WAIT_FOREVER);//thread safe for external users and pcDataServer task

        // Write header
        int headerSend = write(mConnectedSocket, reinterpret_cast<char*>(&anHeader), sizeof(anHeader));

        // Write image length to PC
        int lengthSend = write(mConnectedSocket, reinterpret_cast<char*>(&anLen), sizeof(anLen));

        // Write data
        int sent = write (mConnectedSocket, reinterpret_cast<char*>(apData), anLen);

        // The PC probably closed connection.
        if (headerSend == ERROR || lengthSend == ERROR || sent == ERROR)
        {
                semTake(mServerReadySem,WAIT_FOREVER);
                mbServerReady = false;//set Server to false
                semGive(mServerReadySem);

                close(mConnectedSocket);//close connection
                mConnectedSocket = 0;
                semGive(mCurrentConnectionDone);//allow server task to accept new connection
        }
        semGive(mExternalUserSem);
    }
}

/**
 * Static stub for kicking off the server task
 */
int bhs_PCDataServer::ServerSocketTask(bhs_PCDataServer *apThis)
{
        return apThis->ServerTask();
        return 0;
}

/**
 * @brief Initialize the socket and serve images to the PC.
 * This is the task that serves images to the PC in a loop. This runs
 * as a separate task.
 */
int bhs_PCDataServer::ServerTask()
{
        /* Setup to PC sockets */
        struct sockaddr_in serverAddr;
        int sockAddrSize = sizeof(serverAddr);
        int pcSock = ERROR;
        bzero ((char *) &serverAddr, sockAddrSize);
        serverAddr.sin_len = (u_char) sockAddrSize;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons (VIDEO_TO_PC_PORT);
        serverAddr.sin_addr.s_addr = htonl (INADDR_ANY);

        while (true)
        {
                // Create the socket.
                if ((pcSock = socket (AF_INET, SOCK_STREAM, 0)) == ERROR)
                {
                        perror ("socket");
                        continue;
                }
                // Set the TCP socket so that it can be reused if it is in the wait state.
                int reuseAddr = 1;
                if (setsockopt(pcSock, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char*>(&reuseAddr), sizeof(reuseAddr)) == ERROR)
                {
                        perror("setsockopt");
                        close(pcSock);
                        continue;
                }
                // Bind socket to local address.
                if (bind (pcSock, (struct sockaddr *) &serverAddr, sockAddrSize) == ERROR)
                {
                        perror ("bind");
                        close (pcSock);
                        continue;
                }
                while(true)
                {
                        // Create queue for client connection requests.
                        if (listen (pcSock, 1) == ERROR)
                        {
                                perror ("listen");
                                close (pcSock);
                                break;
                        }

                        struct sockaddr_in clientAddr;
                        int clientAddrSize;

                        mConnectedSocket = accept (pcSock, reinterpret_cast<sockaddr*>(&clientAddr), &clientAddrSize);
                        if (mConnectedSocket  == ERROR)
                        {
                                close(pcSock);
                                break;
                        }
                        else
                        {
                                semTake(mServerReadySem,WAIT_FOREVER);
                                mbServerReady = true;
                                semGive(mServerReadySem);

                                semTake(mCurrentConnectionDone,WAIT_FOREVER);//wait until PC close connection to accept new connection
                        }
                }
                close(pcSock);          
        }
        return (OK);
}

bool bhs_PCDataServer::ready()
{
        return mbServerReady;
}
