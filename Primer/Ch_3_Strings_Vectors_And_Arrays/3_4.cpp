// Exercices on strings
// This scripts reads two strings (two words) and prints out the larger


#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    
    string word1,word2;
    string concatenated;
    
    while(true){
        cout<<"Enter two words separated by space"<<endl; 
        cin>>word1>>word2;   
        if (word1==word2){
            cout<<"strings are equal!: " <<word1<<endl;
        }
        else if(word1>word2){
            cout<<"the largest string is: "<<word1<<endl;
        }
        else{
            cout<<"the largest string is: "<<word2<<endl;
        }
    
        concatenated=word1+" "+word2;
        cout<<"Concatenated String is: " << concatenated<< endl;
    }
    return 0;
}
