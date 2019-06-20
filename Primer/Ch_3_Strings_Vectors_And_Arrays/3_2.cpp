// Exercices on strings
// This scripts reads a line at a time


#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    
    string line; //Create a string
    string word;
    
    while (getline(cin,line))
        if (line.size()>8)  // If string is longer then 8 then prints
            cout<<line<<endl;
    /* If we want to read a word at a time then uncomment below and comment above
      
    while(cin>>word)
        cout<<word<<endl;
    */

    
    return 0;
}
