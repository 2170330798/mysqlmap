#include "../include/domainsys.h"
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
void getIpAddress(const char *source_string, char *ip_address)
{
    WSADATA wsaData;
    HOSTENT *pHostEnt;
    int index = 0;
    struct sockaddr_in   sAddr;
    if (WSAStartup(MAKEWORD(2,2), &wsaData))
    {
        printf(" gethostbyname error for host:\n");
        return;
    }
    pHostEnt = gethostbyname(source_string);
    if (pHostEnt)
    {
        while (pHostEnt->h_addr_list[index])
        {
            memcpy(&sAddr.sin_addr.s_addr, pHostEnt->h_addr_list[index], pHostEnt->h_length);
            sprintf(ip_address, "%s", inet_ntoa(sAddr.sin_addr));
            index++;
        }
    }
    else
    {
        printf("Error: %ld\n",GetLastError());
    }
    WSACleanup();
}
