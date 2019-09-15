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
#include <iostream>
 
#include "modules/Url.cpp"
 
using namespace std; 
 

int main(int argc, char* argv[])
//int main(void)
{
  //https://github.com/a-ishere/a-ishere.github.io
  //https://github.com/a-ishere/a-ishere.github.io/blob/master/index.html
 const   string  errorDomen = "Domen github not found"; 
 const   string  startSearch = "Start search github \n"; 
// const  char* urlPathGit = "https://github.com/a-ishere/a-ishere.github.io";
//const  char* urlPathGit = "https://raw.githubusercontent.com/a-ishere/a-ishere.github.io/master/index.html";
const  string urlPathGit = "https://github.com/";

 // if(argv[1] != NULL){
        cout << startSearch << endl; ;
        
    //  char * urlPathGit = argv[1]; 
        Url * urlLink = new Url();
        urlLink -> getUrl(* urlPathGit);

//  }else{
  //      cout << errorDomen << endl; ;
  // }

        cout << "  \n " << endl; ;
    
  //  Url * urlLink = new Url();
  //  urlLink -> getUrl();
  return 0;
}