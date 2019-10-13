#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>


#include "Url.h"
using namespace std; 
 

Url::Url(){
 const   string indexFile = "/blob/master/index.html"; 

}


/**
*
*
* @url https://stackoverflow.com/questions/9786150/save-curl-content-result-into-a-string-in-c
*/
bool Url::curl_httpget(const string &url)
{


  Url::createFolderTmp();

 
 
 
    CURL *curl;
    CURLcode result;
 
    curl = curl_easy_init();

    std::string tempname = "tmp/tempIndex.txt";

    FILE *fp = fopen(tempname.c_str(),"wb");

    if (curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()  );
      curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L); 
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);  
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L); 

      result = curl_easy_perform(curl);//http get performed
      curl_easy_cleanup(curl);//must cleanup
 
      fclose(fp);

      if (result == CURLE_OK)
     
       return true;
    
    }
 
    return false;
}


bool Url::createFolderTmp()
{
 
  int check; 
  const char * dirname = "tmp"; 
  check = mkdir(dirname, 0755 ); 
  
  // check if directory is created or not 
  if (!check) 
    printf("Directory created\n"); 
  else { 
    printf("Unable to create directory\n"); 
    //exit(1); 
  }
  return true;
}



