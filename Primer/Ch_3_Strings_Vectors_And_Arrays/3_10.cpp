// Exercices on strings
// This scripts reads a string and removes the punctuation symbols


#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    cout<<"Enter a string with ! characters: "<<endl;
    string line1,line2;

    while (getline(cin,line1)){
            for (decltype(line1.size()) index=0; index!=line1.size(); ++index){
                if (!ispunct(line1[index])){
                         line2+=line1[index];
                }
            }
    cout<<"removed punctuation characters in "<< line2 <<endl;
    }
    return 0;
}
