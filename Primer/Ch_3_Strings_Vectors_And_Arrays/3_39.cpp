// This script compares two strings. Both in modern way and in old C way.

#include <string>
#include <iostream>
#include <cstring>


using std::string;

int main(){

    string s1,s2;
    std::cin>>s1>>s2;
    if (s1==s2)
        std::cout<<"Two strings are equal" << std::endl;
    else
        std::cout<<"Two strings are not equal:"<< std::endl;

    // C style char strings

    char cs1[100];
    char cs2[100];

    std::cin>>cs1>>cs2;
    if (!strcmp(cs1,cs2))
        std::cout<<"Two strings are equal" << std::endl;
    else
          std::cout<<"Two strings are not equal" << std::endl;


    return 0;
    
}
