#ifndef MYCURL_H_INCLUDED
#define MYCURL_H_INCLUDED

#define REQUEST_BODY_LEN 14

#define HOST_INDEX 1
#define REQUEST_WAY_INDEX 0
#define ACCEPT_INDXE 4
#define CONNECTION_INDXE 9
#define ACCEPT_ENCODING_INDEX 6
#define ACCEPT_LANGUAGE_INDXE 2
#define USER_AGENT_INDXE 3
#define REFERER_INDEX 5
#define AUTHORIZATION_INDEX 11
#define COOKIE_INDEX 7
#define CONTENT_TYPE_INDXE 8
#define CONTENT_LENGTH_INDEX 10
#define IF_MODIFIED_SINCE_INDEX 12
#define RANGE_INDXE 13
#define URL_LEN 1024
#define PORT_LEN 6 //1~65535

struct HTTP
{
    char **body;
    unsigned int rows;
    unsigned int length;
    unsigned int request_way_length;
    unsigned int host_length;
    unsigned int connection_length;
    unsigned int accept_length;
    unsigned int accept_encoding_length;
    unsigned int accept_language_length;
    unsigned int user_agent_length;
    unsigned int referer_length;
    unsigned int authorization_length;
    unsigned int cookie_length;
    unsigned int content_type_length;
    unsigned int content_length;
    unsigned int if_modified_since_length;
    unsigned int range_length;
};

struct HTTP * initHttp();
void setRequestWay(char *request_way,struct HTTP *http);
void setHost(char *host,struct HTTP *http);
void setAccept(char *accept,struct HTTP *http);
void setConnection(char *connect_way,struct HTTP *http);
void setAcceptEncoding(char *encoding,struct HTTP *http);
void setAcceptLanguage(char *language,struct HTTP *http);
void setUserAgent(char *agent,struct HTTP *http);
void setReferer(char *referer,struct HTTP *http);
void setAuthorization(char *authorization,struct HTTP *http);
void setCookie(char *cookie,struct HTTP *http);
void setContentType(char *content_type,struct HTTP *http);
void setContentLength(char *content_length,struct HTTP *http);
void setIfModifiedSince(char *if_modified_since,struct HTTP *http);
void setRange(char *range,struct HTTP *http);
void urlCode(char *target_url,char *source_url,int url_size);
void freeHttp(struct HTTP *http);

#endif // MYCURL_H_INCLUDED
