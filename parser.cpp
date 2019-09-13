/**
* @author koras
* only linux
* g++ -o parser parser.cpp -lcurl
*
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <curl/curl.h>
 
#include "modules/Url.cpp"


int main(int argc, char **argv)
//int main(void)
{
    Url * urlLink = new Url();
    urlLink -> getUrl();
  return 0;
}