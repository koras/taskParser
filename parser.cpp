#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>

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
//g++  -o  parser parser.cpp -lcurl  -lboost_regex

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


 string question2 = "Where do you live? ";

  // if(argv[1] != NULL){
    
         cout << startSearch << endl; ;
         cout << urlPathGit  << endl; ;
         cout << question2  << endl; ;
        
    //   char * urlPathGit = argv[1]; 
         Url * urlLink = new Url(); 
     //  bool getUrl  = urlLink -> curl_httpget(urlPathGit);
      
     //  if(getUrl){
          
    //   }

         serchPattern();

  // }else{
  //      cout << errorDomen << endl; ;
  //  }

  //  serchPattern();

     //   cout << urlLink  -> indexPage + "  \n " << endl; ;
    
  //  Url * urlLink = new Url();
  //  urlLink -> getUrl();
  return 0;
}


bool serchPattern()
{ 


    std::cout << " serchPattern();" << '\n';
 
  std::string::const_iterator start, end;

   short stringlength = 3072;
   std::string mystring( stringlength, '\0' );
  //ifstream t("tmp/tempIndex.txt");

    std::string tempname = "tmp/tempIndex.txt";

    FILE *file = fopen(tempname.c_str(),"r");

    fseek(file , 0, SEEK_SET);
    fread(&mystring[0], sizeof(char), (size_t)stringlength, file);
    fclose(file);
// вывод текста


  start = mystring.begin(); 
   end = mystring.end(); 

typedef std::map<std::string, int, std::less<std::string> > map_type; 
map_type m ; 
      boost::match_results<std::string::const_iterator> what; 
  // boost::smatch what;

   boost::regex expression(" pattern=\"([\\/\\/\\|\\@\\,\\#\\\\\?\\+\\.\\-\\\\)\\[\\]\\{\\}\\(\\)a-zA-ZаоуыэяеёюибвгдйжзклмнпрстфхцчшщьъАОУЫЭЯЕЁЮИБВГДЙЖЗКЛМНПРСТФХЦЧШЩЬЪ0-9]+)\" ");
//"(https?:\/\/)(www\.)?(((\w[\-]?)+\.\w+)|((\d{2,3}\.){3}\d{2,3}))(:\d{1,5})?([A-Za-z\d\/\.]+#?)
   //std::string::const_iterator start, end; 
   

 boost::match_flag_type flags = boost::match_default; 
   while(regex_search(start, end, what, expression, flags)) 
   { 
      // what[0] contains the whole string 
      // what[5] contains the class name. 
      // what[6] contains the template specialisation if any. 
      // add class name and position to map: 
      m[std::string(what[5].first, what[5].second) + std::string(what[6].first, what[6].second)] = 
                what[5].first - mystring.begin(); 
      // update search position: 
      start = what[0].second; 


      //   std::cout << what << '\n';
         std::cout << what[1] << '\n';
      // update flags: 
      flags |= boost::match_prev_avail; 
      flags |= boost::match_not_bob; 
   } 

 
        // std::cout << m[0]<< '\n';

/*
  boost::regex_token_iterator<std::string::iterator> it(mystring.begin(), mystring.end(), expr, 1);
  boost::regex_token_iterator<std::string::iterator> end;
  while (it != end)
    std::cout << *it++ << '\n';
   std::cout <<  22 << '\n';
 
 

      std::cout <<  mystring << '\n';

   if(boost::regex_search (mystring, what, expr, flags)) 
   { 

 int len = sizeof( mystring);
      
   std::cout <<  what.size() << '\n';
   


    for(int i = 0; i< len ;i++){
      std::cout <<  what[i] << '\n';
      }

    std::cout << what[0] << '\n';
    std::cout << what[1] << '\n';
    std::cout << what[3] << '\n';
    std::cout << what[4] << '\n';
 
   } 
   */
 

  return true;
  }
// @id:ms-vscode.cpptools