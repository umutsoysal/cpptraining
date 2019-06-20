// Exercices on strings
// This scripts makes the characters uppercase and count the punctuation symbols.


#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    
    string s("Hello World!!!");

    decltype(s.size()) punct_cnt=0;

    for (auto &c:s){
        c=toupper(c); // Make it uppercase
        if (ispunct(c))   // Count the punctions 
            ++punct_cnt;
    }
    cout<<punct_cnt<<" punctuation characters in "<< s <<endl;

    string p("some string");
    for (decltype(s.size()) index=0;
         index!=p.size() && !isspace(p[index]);index ++)
         p[index]=toupper(p[index]); //capitalize the current character

    cout<< p <<endl;
    return 0;
}
