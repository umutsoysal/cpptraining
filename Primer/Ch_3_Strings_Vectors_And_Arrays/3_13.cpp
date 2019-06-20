// Exercices on strings
// This scripts shows different initialization methods for vectors


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;



int main(){

    vector<int> v1;
    vector<int> v2(10);
    vector<int>v3(10,42);
    vector<int>v4{10};
    vector<int>v5{10,42};
    vector<string>v6{10};
    vector<string>v7{10,"hi"};

    cout<<"size of v1: "<<v1.size()<<endl;    
    for (auto j:v1)
        cout<<j<<" ";
    cout<<endl;
    cout<<"size of v2: "<<v2.size()<<endl;
    for (auto j:v2)
        cout<<j<<" ";
    cout<<endl;
    cout<<"size of v3: "<<v3.size()<<endl;
    for (auto j:v3)
        cout<<j<<" ";
    cout<<endl;
    cout<<"size of v4: "<<v4.size()<<endl;
    for (auto j:v4)
        cout<<j<<" ";
    cout<<endl;
        cout<<"size of v1: "<<v1.size()<<endl;
    for (auto j:v5)
        cout<<j<<" ";
    cout<<endl;
        cout<<"size of v1: "<<v1.size()<<endl;
    for (auto j:v6)
        cout<<j<<" ";
    cout<<endl;
        cout<<"size of v1: "<<v1.size()<<endl;
    for (auto j:v7)
        cout<<j<<" ";
    cout<<endl;
    
    return 0;
}
