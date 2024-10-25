#include "../include/sqlinject.h"
#include "../include/commen.h"
#include "../include/mycurl.h"
#include "../include/mytcp.h"
#include "../include/mystring.h"
#include "../include/domainsys.h"
#include <stdio.h>
#include <stdlib.h>

char ip[IP_LEN];
char url[URL_LEN];
char host[HOST_MAX_LEN];
char sql[SQL_MAX_LEN];
char temp[DEFAULT_BUFLEN/4];
char dir_path[FILE_PATH_LEN];
char port[PORT_LEN];

void usage()
{
    printf("\n\n");
    printf("\t\t==================handbook================\n");
    printf("\t\t 1  character sql inject\n");
    printf("\t\t 2  search based sql inject\n");
    printf("\t\t 3  xxx sql inject\n");
    printf("\t\t 4  blind sql inject\n");
    printf("\n\n");
    unsigned int option;
    printf("sqlmap/handbook> ");
    scanf("%d",&option);
    sprintf(dir_path,"%s%s%d.txt",DUCUMENT_PATH,"eusage",option);
    FILE *fp = fopen(dir_path, "r");
    if(fp == NULL)
        return ;
    while(!feof(fp))
    {
        fgets(temp, DEFAULT_BUFLEN/4, fp);
        printf("%s\n",temp);
    }
    fclose(fp);
}


void sql_inject()
{
    struct HTTP *http = initHttp();
    /**set request body**/
    fflush(stdin);//flush the stdin buffer
    printf("sqlmap/input url> ");
    gets(url);
    printf("sqlmap/input sql> ");
    gets(sql);
    /********************/




    /********************/

    getIpAddress(host, ip);
    struct TCP  *tcp  = initTcp(ip, 80);
    for(int i=0; i<REQUEST_BODY_LEN; i++)
        puts(http->body[i]);
    sprintf(dir_path,"%s%s", FILE_RECV_PATH,"recv.html");
    sendResponse(dir_path, http->body, REQUEST_BODY_LEN, tcp);
    //system(dir_path);
    freeHttp(http);
    freeTcp(tcp);
}
