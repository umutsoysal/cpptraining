
//Repeat the previous program, but read values into a list of strings


#include <iostream>

#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main(){

    // search in strings
    string value="GAN"; //search for this literal

    list <string> lst={"CNN","DRL","GAN","SVM","GAN","KNN","EM","GMM","GAN"};
    
    auto result2=count(lst.cbegin(),lst.cend(),value);

    cout<<"The string "<<value<<" has been occured " <<result2<<" times." <<endl;
    return 0;
}

