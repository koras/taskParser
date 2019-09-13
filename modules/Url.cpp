#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>

#include "Url.h"

Url::Url(){

}


int Url::getUrl()
{


        CURL *curl;
        CURLcode res;
        
        curl_global_init(CURL_GLOBAL_ALL);
        
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        
            /* get the first document */ 
            curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/");
        
            /* Perform the request, res will get the return code */ 
            res = curl_easy_perform(curl);
            /* Check for errors */ 
            if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
            /* get another document from the same server using the same
            connection */ 
            curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/docs/");
        
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