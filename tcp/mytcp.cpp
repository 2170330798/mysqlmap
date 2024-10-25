#include "../include/mytcp.h"
#include "../include/commen.h"
#include "../include/mystring.h"

#include <stdio.h>
#include <winsock2.h>

struct TCP * initTcp(char *ip, unsigned int port)
{
    struct TCP *tcp = (struct TCP*)malloc(sizeof(struct TCP));
    tcp->recvbuflen = DEFAULT_BUFLEN;
    tcp->sendbuflen = DEFAULT_BUFLEN;
    tcp->default_port = port;
    tcp->ip = (char*)malloc(sizeof(char)*IP_LEN);
    strcpy(tcp->ip,ip);
    tcp->recvbuf = (char*)malloc(sizeof(char)*(tcp->recvbuflen));
    tcp->sendbuf = (char*)malloc(sizeof(char)*(tcp->sendbuflen));
    tcp->ConnectSocket = INVALID_SOCKET;
    tcp->iResult = WSAStartup(MAKEWORD(2,2), &(tcp->wsaData));
    if (tcp->iResult != NO_ERROR)
    {
        printf("WSAStartup failed: %d\n", tcp->iResult);
        return NULL;
    }
    return tcp;
}

void freeTcp(struct TCP *tcp)
{
    free(tcp->ip);
    free(tcp->recvbuf);
    free(tcp->sendbuf);
    closesocket(tcp->ConnectSocket);
    free(tcp);
    WSACleanup();
}

void sendResponse(char *recv_file, char **request, unsigned int request_rows,struct TCP *tcp)
{
    tcp->clientService.sin_family = AF_INET;
    tcp->clientService.sin_addr.s_addr = inet_addr(tcp->ip);
    tcp->clientService.sin_port = htons(tcp->default_port);

    tcp->ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tcp->ConnectSocket == INVALID_SOCKET)
    {
        printf("Error at socket(): %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    tcp->iResult = connect( tcp->ConnectSocket, (SOCKADDR*) &tcp->clientService, sizeof(tcp->clientService) );
    if ( tcp->iResult == SOCKET_ERROR)
    {
        closesocket (tcp->ConnectSocket);
        printf("Unable to connect to server: %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    char *off_set = tcp->sendbuf;
    for(unsigned int i=0;i<request_rows;i++)
    {
        if(request[i] != NULL)
            off_set = mystrcpy(tcp->sendbuf, request[i], tcp->sendbuflen, strlen(request[i]), off_set);
    }

    // Send an initial buffer
    tcp->iResult = send( tcp->ConnectSocket, tcp->sendbuf, (int)strlen(tcp->sendbuf), 0 );
    if (tcp->iResult == SOCKET_ERROR)
    {
        printf("send failed: %d\n", WSAGetLastError());
        closesocket(tcp->ConnectSocket);
        WSACleanup();
        return;
    }
    printf("Send %d\n", tcp->iResult);
    // shutdown the connection since no more data will be sent
    tcp->iResult = shutdown(tcp->ConnectSocket, SD_SEND);
    if (tcp->iResult == SOCKET_ERROR)
    {
        printf("shutdown failed: %d\n", WSAGetLastError());
        closesocket(tcp->ConnectSocket);
        WSACleanup();
        return;
    }
    // Receive until the peer closes the connection
    FILE *fp = fopen(recv_file,"w+");
    if(fp == NULL)
    {
        printf("Can't open and create this file! %s\n",recv_file);
        return;
    }

    do
    {
        tcp->iResult = recv(tcp->ConnectSocket, tcp->recvbuf, tcp->recvbuflen, 0);
        if ( tcp->iResult > 0 )
        {
            fputs(tcp->recvbuf, fp);
            printf("Received %d\n",tcp->iResult);
        }
        else if(tcp->iResult == 0)
        {
             fclose(fp);
        }
        else
            printf("recv failed: %d\n", WSAGetLastError());
    }
    while( tcp->iResult > 0 );
}
