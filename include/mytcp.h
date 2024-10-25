#ifndef MYTCP_H_INCLUDED
#define MYTCP_H_INCLUDED

#include <winsock2.h>
#include <windows.h>

struct TCP
{
    WSADATA wsaData;
    int iResult;
    unsigned int default_port;
    char *recvbuf;
    char *sendbuf;
    char *ip;
    int recvbuflen;
    int sendbuflen;
    SOCKET ConnectSocket;
    SOCKET ReceiveSocket;
    struct sockaddr_in clientService;
    struct sockaddr_in serverService;
};

struct TCP * initTcp(char *ip, unsigned int port);
void fillSendBuf(char *target,char *source,struct TCP *tcp);
void freeTcp(struct TCP *tcp);
void sendResponse(char *recv_file,
               char **request,
               unsigned int request_rows,
               struct TCP *tcp);


#endif // MYTCP_H_INCLUDED
