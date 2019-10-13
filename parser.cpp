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
//#include "modules/http/Url.cpp"
 
using namespace std; 
//using namespace std::tr1;
 
 bool serchPattern();

int main(int argc, char* argv[])
{

    serchPattern();
// string name, family;

//   //https://github.com/a-ishere/a-ishere.github.io
//   //https://github.com/a-ishere/a-ishere.github.io/blob/master/index.html
//  const   string  errorDomen = "Domen github not found"; 
//  const   string  startSearch = "Start search github \n"; 
// // const  char* urlPathGit = "https://github.com/a-ishere/a-ishere.github.io";
// //const  char* urlPathGit = "https://raw.githubusercontent.com/a-ishere/a-ishere.github.io/master/index.html";

//  // char  urlPathGit[150] = "https://github.com/Ekaterina1618/Ekaterina1618.github.io";
//         //       https://github.com/Ekaterina1618/Ekaterina1618.github.io
// //https://raw.githubusercontent.com/Ekaterina1618/Ekaterina1618.github.io/master/index.html


// char  urlPathGit[150] = "https://raw.githubusercontent.com/Ekaterina1618/Ekaterina1618.github.io/master/index.html";


// string question2 = "Where do you live? ";

//   if(argv[1] != NULL){
    
//         cout << startSearch << endl; ;
//         cout << urlPathGit  << endl; ;
//         cout << question2  << endl; ;
        
//       char * urlPathGit = argv[1]; 
//         Url * urlLink = new Url(); 
//       bool getUrl  = urlLink -> curl_httpget(urlPathGit);
      
//       if(getUrl){
         
//       }


//   }else{
//         cout << errorDomen << endl; ;
//    }

  //  serchPattern();

     //   cout << urlLink  -> indexPage + "  \n " << endl; ;
    
  //  Url * urlLink = new Url();
  //  urlLink -> getUrl();
  return 0;
}


bool serchPattern()
{ 

  //ifstream t("tmp/tempIndex.txt");
/**
  ifstream htmlText;
  string line;
  string eduEmail = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";


  int testNum = 0;

  //list<string> l;
  &regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

    //regex_t  re;
    
   // regex integer("(\\+|-)?[[:digit:]]+");


  htmlText.open("tmp/tempIndex.txt");
  if (htmlText.good())
  {
      while (getline(htmlText, line))
      {
          regex e(eduEmail); // the pattern

          bool match = regex_search(line, e);
          if (match) {
            ++testNum;
        }
      }
  }

  htmlText.close();

  system("pause");


*/


 //  regex_t    preg;                                                            
  //    std::string  string = "a simple string";                                     
  //   std::string  pattern = ".*(simple).*";                                       
  //   int        rc;                                                              
  //   size_t     nmatch = 2;                                                      
  //  // regmatch_t pmatch[2];                                                       
                                                                                
  //   if ((rc = regcomp(&preg, pattern, REG_EXTENDED)) != 0) {                    
  //      printf("regcomp() failed, returning nonzero (%d)\n", rc);                
  //      exit(1);                                                                 
  //   }                                                                           
                                                                                
  //   if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {                
  //      printf("failed to ERE match '%s' with '%s',returning %d.\n",   string, pattern, rc);                                                    
  //   }                                                                           
                                                                                
  //   regfree(&preg);  







     std::regex e("(a.*cd)", regex::extended);
    string s = R"(abcd cd abefcd ababcddecd)";
    string match = "";
    size_t i = 0;
    while (s.size() > i)
    {
        smatch m;
        string ss = s.substr(0, i);

        regex_search(ss, m, e);
        if (m.size() > 1 && m[1] != match) {
            cout << m[1] << endl; 
            match = m[1];
        }
        i++;
    }
        cin.get();













  return true;
  }
// @id:ms-vscode.cpptools