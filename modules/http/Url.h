#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include <string>
using namespace std; 
    /**
    *
    * here get all info into github.com
    *
    */
class Url {
    public:
       Url();    
       
    bool curl_httpget(const string &url);
    
    bool createFolderTmp();

    std::string indexPage;
    std::string getBranches;
    std::string getReadme;  

};