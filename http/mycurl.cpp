#include "../include/mycurl.h"
#include "../include/mystring.h"
#include <string.h>
#include <stdlib.h>

struct HTTP * initHttp()
{
    struct HTTP *http = (struct HTTP*)malloc(sizeof(struct HTTP));
    http->body = (char**)malloc(sizeof(char*)*REQUEST_BODY_LEN);
    for(int i=0; i<REQUEST_BODY_LEN; i++)
        http->body[i] = NULL;
    return http;
}

void setRequestWay(char *request_way, struct HTTP *http)
{
    http->request_way_length = strlen(request_way);
    http->body[REQUEST_WAY_INDEX] = (char*)malloc(sizeof(char)*http->request_way_length);
    char *off_set = http->body[REQUEST_WAY_INDEX];
    mystrcpy(http->body[REQUEST_WAY_INDEX],request_way,http->request_way_length,http->request_way_length,off_set);
}

void setHost(char *host,struct HTTP *http)
{
    http->host_length = strlen(host);
    http->body[HOST_INDEX] = (char*)malloc(sizeof(char)*http->host_length);
    char *off_set = http->body[HOST_INDEX];
    mystrcpy(http->body[HOST_INDEX], host,http->host_length,http->host_length,off_set);
}

void setAccept(char *accept,struct HTTP *http)
{
    http->accept_length = strlen(accept);
    http->body[ACCEPT_INDXE] = (char*)malloc(sizeof(char)*http->accept_length);
    char *off_set = http->body[ACCEPT_INDXE];
    mystrcpy(http->body[ACCEPT_INDXE], accept,http->accept_length,http->accept_length,off_set);
}

void setConnection(char *connect_way,struct HTTP *http)
{
    http->connection_length = strlen(connect_way);
    http->body[CONNECTION_INDXE] = (char*)malloc(sizeof(char)*http->connection_length);
    char *off_set = http->body[CONNECTION_INDXE];
    mystrcpy(http->body[CONNECTION_INDXE], connect_way,http->connection_length,http->connection_length,off_set);
}

void setAcceptEncoding(char *encoding,struct HTTP *http)
{
    http->accept_encoding_length = strlen(encoding);
    http->body[ACCEPT_ENCODING_INDEX] = (char*)malloc(sizeof(char)*http->accept_encoding_length);
    char *off_set = http->body[ACCEPT_ENCODING_INDEX];
    mystrcpy(http->body[ACCEPT_ENCODING_INDEX], encoding,http->accept_encoding_length,http->accept_encoding_length,off_set);
}

void setAcceptLanguage(char *language,struct HTTP *http)
{
    http->accept_language_length = strlen(language);
    http->body[ACCEPT_LANGUAGE_INDXE] = (char*)malloc(sizeof(char)*http->accept_language_length);
    char *off_set = http->body[ACCEPT_LANGUAGE_INDXE];
    mystrcpy(http->body[ACCEPT_LANGUAGE_INDXE], language,http->accept_language_length,http->accept_language_length,off_set);
}

void setUserAgent(char *agent,struct HTTP *http)
{
    http->user_agent_length = strlen(agent);
    http->body[USER_AGENT_INDXE] = (char*)malloc(sizeof(char)*http->user_agent_length);
    char *off_set = http->body[USER_AGENT_INDXE];
    mystrcpy(http->body[USER_AGENT_INDXE], agent,http->user_agent_length,http->user_agent_length,off_set);
}

void setReferer(char *referer,struct HTTP *http)
{
    http->referer_length = strlen(referer);
    http->body[REFERER_INDEX] = (char*)malloc(sizeof(char)*http->referer_length);
    char *off_set = http->body[REFERER_INDEX];
    mystrcpy(http->body[REFERER_INDEX], referer,http->referer_length,http->referer_length,off_set);
}

void setAuthorization(char *authorization,struct HTTP *http)
{
    http->authorization_length = strlen(authorization);
    http->body[AUTHORIZATION_INDEX] = (char*)malloc(sizeof(char)*http->authorization_length);
    char *off_set = http->body[AUTHORIZATION_INDEX];
    mystrcpy(http->body[AUTHORIZATION_INDEX], authorization,http->authorization_length,http->authorization_length,off_set);
}

void setCookie(char *cookie,struct HTTP *http)
{
    http->cookie_length = strlen(cookie);
    http->body[COOKIE_INDEX] = (char*)malloc(sizeof(char)*http->cookie_length);
    char *off_set = http->body[COOKIE_INDEX];
    mystrcpy(http->body[COOKIE_INDEX], cookie,http->cookie_length,http->cookie_length,off_set);
}
void setContentType(char *content_type,struct HTTP *http)
{
    http->content_type_length = strlen(content_type);
    http->body[CONTENT_TYPE_INDXE] = (char*)malloc(sizeof(char)*http->content_type_length);
    char *off_set = http->body[CONTENT_TYPE_INDXE];
    mystrcpy(http->body[CONTENT_TYPE_INDXE], content_type,http->content_type_length,http->content_type_length,off_set);
}

void setContentLength(char *content_length,struct HTTP *http)
{
    http->content_length = strlen(content_length);
    http->body[CONTENT_LENGTH_INDEX] = (char*)malloc(sizeof(char)*http->content_length);
    char *off_set = http->body[CONTENT_LENGTH_INDEX];
    mystrcpy(http->body[CONTENT_LENGTH_INDEX], content_length,http->content_length,http->content_length,off_set);
}

void setIfModifiedSince(char *if_modified_since,struct HTTP *http)
{
    http->if_modified_since_length = strlen(if_modified_since);
    http->body[IF_MODIFIED_SINCE_INDEX] = (char*)malloc(sizeof(char)*http->if_modified_since_length);
    char *off_set = http->body[IF_MODIFIED_SINCE_INDEX];
    mystrcpy(http->body[IF_MODIFIED_SINCE_INDEX], if_modified_since,http->if_modified_since_length,http->if_modified_since_length,off_set);
}

void setRange(char *range,struct HTTP *http)
{
    http->range_length = strlen(range);
    http->body[RANGE_INDXE] = (char*)malloc(sizeof(char)*http->range_length);
    char *off_set = http->body[RANGE_INDXE];
    mystrcpy(http->body[RANGE_INDXE], range, http->range_length, http->range_length, off_set);
}

void freeHttp(struct HTTP *http)
{
    for(int i=0; i<REQUEST_BODY_LEN; i++)
        free(http->body[i]);
    free(http->body);
    free(http);
}

void urlCode(char *target_url,char *source_url,int source_url_len)
{
    char code[][4]=
    {
        "%20",//0
        "%21",//1
        "%22",//2
        "%23",//3
        "%24",//4
        "%25",//5
        "%26",//6
        "%27",//7
        "%28",//8
        "%29",//9
    };
    int j = 0;
    char *off_set = target_url;
    for(int i=0; i<source_url_len; i++)
    {
        if(source_url[i] >= ' ' && source_url[i] <= '~')
        {
            if(source_url[i] == ' ')
                off_set = mystrcpy(target_url, code[0], source_url_len, sizeof(code[0]), off_set);
            else if(source_url[i] == '"')
                off_set = mystrcpy(target_url, code[2], source_url_len, sizeof(code[2]), off_set);
            else if(source_url[i] == '#')
                off_set = mystrcpy(target_url, code[3], source_url_len, sizeof(code[3]), off_set);
            else if(source_url[i] == '%')
                off_set = mystrcpy(target_url, code[5], source_url_len, sizeof(code[5]), off_set);
            else if(source_url[i] == '\'')
                off_set = mystrcpy(target_url, code[7], source_url_len, sizeof(code[7]), off_set);
            else if(source_url[i] == '(')
                off_set = mystrcpy(target_url, code[8], source_url_len, sizeof(code[8]), off_set);
            else if(source_url[i] == ')')
                off_set = mystrcpy(target_url, code[9], source_url_len, sizeof(code[9]), off_set);
            else
            {
                target_url[j++] = source_url[i];
                //保证j 与 off_set指的同一个地址
                off_set = (target_url+j);
            }
            //保证j 与 off_set指的同一个地址
            j = (int)(off_set - target_url);
        }
    }
}
