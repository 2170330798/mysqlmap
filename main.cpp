
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "include/mycurl.h"
#include "include/mytcp.h"
#include "include/domainsys.h"
#include "include/commen.h"
#include "include/mystring.h"
#include "include/sqlinject.h"

void menu()
{
    printf("\n\n");
    printf("\t\t==================Usage================\n");
    printf("\t\t -1  input 1 start to sql inject\n");
    printf("\t\t -2  input 2 open the handbook\n");
    printf("\t\t -3  input 3 open the menu for help\n");
    printf("\t\t -4  input 4 to exit\n");
    printf("\n\n");
}


void test()
{
    char host[HOST_MAX_LEN] = "www.baidu.com";
    struct HTTP *http = initHttp();
    char ip[IP_LEN];
    getIpAddress(host, ip);
    struct TCP  *tcp = initTcp(ip,443);
    setAccept((char*)"Accept: text/html\r\n\r\n",http);
    setRequestWay((char*)"GET /Less-5/?id=1 HTTP/1.1\r\n",http);
    setHost((char*)"Host: sqli-labs.bachang.org\r\n", http);
    for(int i=0;i<REQUEST_BODY_LEN;i++)
        fputs(http->body[i], stdout);
    char filename[FILE_NAME_LEN] = "";
    sprintf(filename,"%s%s",FILE_RECV_PATH,"recv.html");
    sendResponse(filename, http->body, REQUEST_BODY_LEN, tcp);
    freeHttp(http);
    freeTcp(tcp);
    system(filename);
}

void start()
{
    menu();
    printf("sqlmap> ");
    while(true)
    {
        switch(getchar())
        {
        case '1':
            sql_inject();
            break;
        case '2':
            usage();
            break;
        case '3':
            menu();
            break;
        case '4':
            exit(0);
            break;
         case '\n':
            printf("sqlmap> ");
            break;
        }
    }

}

int main()
{
        test();
	start();
	return 0;
}

