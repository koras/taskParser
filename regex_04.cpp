#include <iostream>
#include <string>
#include <boost/regex.hpp>  // Boost.Regex lib
#include <boost/config.hpp>


using namespace std;

int main()
{
   boost::smatch what;
   std::string s = " <input class=\"form__input\" pattern=\"[А-ЯЁ][а-яё]*(-[А-ЯЁ][а-яё]*)?\" required />"; 
   boost::regex expr(" pattern=\"([\\W]*)\" ");
 

  // std::cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
       


       

   if (boost::regex_search(s, what, expr))
  {
    std::cout << what[0] << '\n';
    std::cout << what[1] << " " << what[2] << '\n';
  }


}
// g++  -o  parser regex_04.cpp -lcurl  -lboost_regex
// https://theboostcpplibraries.com/boost.regex

/*
 URI (protocol://server/path): ([a-zA-Z][a-zA-Z0-9]*)://([^ /]+)(/[^ ]*)?
Email (name@server): ([^ @]+)@([^ @]+)
Date (month/day/year): ([0-9][0-9]?)/([0-9][0-9]?)/([0-9][0-9]([0-9][0-9])?)
URI|Email: ([a-zA-Z][a-zA-Z0-9]*)://([^ /]+)(/[^ ]*)?|([^ @]+)@([^ @]+)

http://www.cs.fsu.edu/~engelen/doc/reflex/html/index.html
*/