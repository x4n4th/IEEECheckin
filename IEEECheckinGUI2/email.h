#pragma once
#pragma warning ( disable : 4005 )

#include <windows.h> 
#include <stdio.h>
#include <io.h>
#include <iostream>
#include <string>

#define snprintf _snprintf_s


static void sendmail_write(const int  sock,const char *str,const char *arg);


static int sendmail(const char *from, const char *to, const char *subject, const char *body, const char *hostname, const int   port);


void SendEmail(std::string email);
