#ifndef HTTPINFO_H_INCLUDED
#define HTTPINFO_H_INCLUDED

#define HEADS 15    //HEADS
#define HEADS_LEN

struct Request{

    unsigned int reqbody_rows;
    unsigned int reqbody_length;
    char **body;

}*req;


void init_request_body(unsigned rows)
{
    req = (struct Request*)malloc(sizeof(struct Request));
    req->reqbody_rows = rows;
    req->body = (char**)malloc(sizeof(char*)(req->reqbody_rows));
}

/*
     "GET /vul/sqli/sqli_blind_b.php?name=lili&submit=%E6%9F%A5%E8%AF%A2 HTTP/1.1\r\n",
     "Host: 192.168.135.128\r\n"
     "Accept: text/html\r\n\r\n",
*/
void setGetRequest()
{
     sprintf(HEAD[0],"%s",);
}

void setAccept(char *accept)
{
     sprintf(HEAD[2],"%s",accept);
}


#endif // HTTPINFO_H_INCLUDED
