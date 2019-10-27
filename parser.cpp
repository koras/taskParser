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

using namespace boost; 
//using namespace std::tr1;
 
 bool serchPattern();
 void  checkPattern();

bool checkName(std::string name);


//g++  -o  parser parser.cpp -lcurl  -lboost_regex

  std::string  regulars[4] ; 
 


int main(int argc, char* argv[])
{
 
 string name, family;
 
  const   string  errorDomen = "Domen github not found"; 
  const   string  startSearch = "Start search github \n";  

 char  urlPathGit[150] = "https://raw.githubusercontent.com/Ekaterina1618/Ekaterina1618.github.io/master/index.html";

 
  // if(argv[1] != NULL){
    
         cout << startSearch << endl; ;
         cout << urlPathGit  << endl; ; 
        
    //   char * urlPathGit = argv[1]; 
         Url * urlLink = new Url(); 
     //  bool getUrl  = urlLink -> curl_httpget(urlPathGit);
      
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
  //  for (int i=0; i<4; i++){
      // we have only four pattern
      

  //  }
     checkName(regulars[0]);


    //    cout << regulars[i] << "\n"; 
}


// https://www.boost.org/doc/libs/1_50_0/libs/regex/doc/html/boost_regex/syntax/basic_extended.html
bool checkName(std::string name){
  //  boost::regex regx;
 //  // regx.assign(name);
    //  setlocale (LC_CTYPE, "Russian_Russia.1251");
       boost::cmatch what; 

  char *current = setlocale (LC_CTYPE, NULL);
      std::locale::global(std::locale(""));
    name = "^" + name+"$";
    boost::match_flag_type flags = boost::match_default; 

 //  while(regex_search(start, end, what, regx, flags)) 

   //   if (boost::regex_match("ЁмаёАяё",  what, boost::regex( name , boost::regex::extended),flags ))
      if (boost::regex_match("ая",  what, boost::regex( name ),flags ))
        {
            std::cout << "Ok , it fine" <<  '\n';
            std::cout <<  what[0] << '\n';
            std::cout <<  what[1] << '\n';
            std::cout <<  what[2] << '\n';
            std::cout << name << '\n';
        }
        else
        {
            std::cout << "Third example should have matched the regex" << '\n';
            std::cout << name << '\n';
        }

  return true;
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