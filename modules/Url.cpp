#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include <iostream>

#include "Url.h"
using namespace std; 

Url::Url(){

}


int Url::getUrl( char  urlPath)
{
             cout << urlPath << endl;
    return 0;
 const   char * indexFile = "/blob/master/index.html"; 
        ///blob/master/index.html
        
        CURL *curl;
        CURLcode res;
        
        curl_global_init(CURL_GLOBAL_ALL);
        
        curl = curl_easy_init();


                cout << urlPath << endl;
    return 0;
        
        if(curl) { 
            /* get the first document */ 

                cout << urlPath << endl;

            curl_easy_setopt(curl, CURLOPT_URL, urlPath);
 

            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
 
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);  
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); 
          
            /* Perform the request, res will get the return code */ 
            res = curl_easy_perform(curl);
            /* Check for errors */ 
    
            if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
         
            /* get another document from the same server using the same
            connection */ 
           // curl_easy_setopt(curl, CURLOPT_URL, urlPath+indexFile);
           curl_easy_setopt(curl, CURLOPT_URL, urlPath);
        
            /* Perform the request, res will get the return code */ 
            res = curl_easy_perform(curl);
            /* Check for errors */ 
            if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
            /* always cleanup */ 
            curl_easy_cleanup(curl);
        }
    
    return 0;
    }