#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include <string>
  

class Url {
 
    public:

       Url();
       //char (&str)[150]
 
       int getUrl(char  urlPath);
};