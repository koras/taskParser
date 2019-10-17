#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <locale>
//#include <regex.h>     
 
//#include <regex>
//#include <tr1/regex>

#include <sstream>
#include <fstream>
#include <curl/curl.h>
#include <iostream>
#include "modules/http/Url.cpp"
 
 
#include <boost/regex.hpp>  // Boost.Regex lib
#include <boost/config.hpp>

using namespace std; 
//using namespace std::tr1;
 
 bool serchPattern();
 void  checkPattern();
//g++  -o  parser parser.cpp -lcurl  -lboost_regex

  std::string  regulars[4] ; 
 


int main(int argc, char* argv[])
{
 
 string name, family;

   //https://github.com/a-ishere/a-ishere.github.io
   //https://github.com/a-ishere/a-ishere.github.io/blob/master/index.html
  const   string  errorDomen = "Domen github not found"; 
  const   string  startSearch = "Start search github \n"; 
 // const  char* urlPathGit = "https://github.com/a-ishere/a-ishere.github.io";
 //const  char* urlPathGit = "https://raw.githubusercontent.com/a-ishere/a-ishere.github.io/master/index.html";

  // char  urlPathGit[150] = "https://github.com/Ekaterina1618/Ekaterina1618.github.io";
         //       https://github.com/Ekaterina1618/Ekaterina1618.github.io
 //https://raw.githubusercontent.com/Ekaterina1618/Ekaterina1618.github.io/master/index.html


 char  urlPathGit[150] = "https://raw.githubusercontent.com/Ekaterina1618/Ekaterina1618.github.io/master/index.html";

 
  // if(argv[1] != NULL){
    
         cout << startSearch << endl; ;
         cout << urlPathGit  << endl; ; 
        
    //   char * urlPathGit = argv[1]; 
         Url * urlLink = new Url(); 
       bool getUrl  = urlLink -> curl_httpget(urlPathGit);
      
     //  if(getUrl){
          
    //   }

         serchPattern();

         checkPattern();

  // }else{
  //      cout << errorDomen << endl; ;
  //  }

  //  serchPattern();

     //   cout << urlLink  -> indexPage + "  \n " << endl; ;
    
  //  Url * urlLink = new Url();
  //  urlLink -> getUrl();
  return 0;
}



void  checkPattern(){
  // Print Strings stored in Vector 
    for (int i=0; i<4; i++)     
        cout << regulars[i] << "\n"; 
}

bool serchPattern()
{  
  // std::locale::global(std::locale("russian"));
  std::locale::global(std::locale(""));
    std::cout << "" << '\n';
 
  std::string::const_iterator start, end;
  short stringlength = 3072;
  std::string mystring( stringlength, '\0' );

    std::string tempname = "tmp/tempIndex.txt";

    FILE *file = fopen(tempname.c_str(),"r");

    fseek(file , 0, SEEK_SET);
    fread(&mystring[0], sizeof(char), (size_t)stringlength, file);
    fclose(file);

   start = mystring.begin(); 
   end = mystring.end(); 

   boost::match_results<std::string::const_iterator> what; 

    boost::regex regx;
    // regx.imbue(std::locale("russian"));
    regx.assign(" pattern=\"([\\/\\:\\/\\|\\@\\,\\#\\\\\?\\+\\.\\-\\\\)\\[\\]\\{\\}\\(\\)a-zA-Zа-яА-ЯёЁйЙыЫ0-9]+)\" ");

  int iIterator = 0 ;
 
    boost::match_flag_type flags = boost::match_default; 
 
   while(regex_search(start, end, what, regx, flags)) 
   { 
      start = what[0].second; 
      regulars[iIterator] = what[1];
      iIterator ++;
   } 

       

  return true;
  }




// @id:ms-vscode.cpptools