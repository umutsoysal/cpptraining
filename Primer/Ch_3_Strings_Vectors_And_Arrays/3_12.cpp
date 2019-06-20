// Exercices on strings
// This scripts reads a string and removes the punctuation symbols


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;



int main(){

    vector<int> v2;
    int i;
    while (cin>>i){
        v2.push_back(i);
        for (auto j:v2)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
