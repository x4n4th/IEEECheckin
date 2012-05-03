#include "email.h"

#define snprintf _snprintf_s
#define PORT 25


static void sendmail_write(const int  sock,const char *str,const char *arg, bool show)
 {
    char buf[4096];

    if (arg != NULL)
        snprintf(buf, sizeof(buf), str, arg);
    else
        snprintf(buf, sizeof(buf), str);

    send(sock, buf, strlen(buf), 0);
    
    if(show)
    {
        char outbuf[1024];
        int len=recv(sock,outbuf,1024,0);
        outbuf[len]='\0';
        std::cout <<outbuf;
    }
}



static int sendmail(const char *from, const char *to, const char *subject, const char *body, const char *hostname, const int   port) 
{

    struct hostent *host;
    struct sockaddr_in saddr_in;
    int sock = 0;


    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return -1;
    }


    sock = socket(AF_INET, SOCK_STREAM, 0);
    host = gethostbyname(hostname);

    saddr_in.sin_family      = AF_INET;
    saddr_in.sin_port        = htons((u_short)port);
    saddr_in.sin_addr.s_addr = 0;

    memcpy((char*)&(saddr_in.sin_addr), host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*)&saddr_in, sizeof(saddr_in)) == -1) {
        return -2;
    }


    sendmail_write(sock, "HELO %s\n", "IEEE", true);

    sendmail_write(sock, "MAIL FROM: %s\n", from, true);    // from
    sendmail_write(sock, "RCPT TO: %s\n",   to, true);      // to
    sendmail_write(sock, "DATA\n",          NULL, true);    // begin data
    sendmail_write(sock, "From: %s\n",      from, false);
    sendmail_write(sock, "To: %s\n",        to, false);
    sendmail_write(sock, "Subject: %s\n",   subject, false);
    sendmail_write(sock, "\n",              NULL, false);
    sendmail_write(sock, "%s\n",            body, false);    // data
    sendmail_write(sock, "%s\n",             ".", false);    // end data
    sendmail_write(sock, "QUIT\n",          NULL, true);    // terminate


    closesocket(sock);

    return 0;
}



void SendEmail(std::string email) 
{
    std::string body = "ADD L-IEEE " + email;
    
    //std::string body = "ADD L-IEEE " + email + " (" + name + ")";

    int ret = sendmail(
        "IEEECheckinSystem@psu.edu",  // from
        "djl5198@psu.edu", // to
        "Listserv Subscription",
        body.c_str(),
        "smtp.psu.edu",
        PORT
    );
   
    body = "Welcome to the Penn State IEEE Branch";

    ret = sendmail(
        "IEEECheckinSystem@psu.edu",  // from
        email.c_str(), // to
        "Listserv Subscription",
        body.c_str(),
        "smtp.psu.edu",
        PORT
    );

     if (ret != 0)
        fprintf(stderr, "Failed to send mail (code: %i).\n", ret);
    else
        fprintf(stdout, "Mail successfully sent.\n");
}