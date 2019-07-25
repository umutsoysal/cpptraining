
// Determine if there are any errors in the following programs and, if so, correct the error(s)

//a

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(){

    vector<int>vec;
    list<int>lst;
    int i;

    while(cin>>i)
        lst.push_back(i);
    // vector should be resized before copy
    vec.resize(lst.size());
    copy(lst.cbegin(),lst.cend(),vec.begin());

    cout<<vec.size()<<endl;

    vector<int>vec2;
    vec2.reserve(10);
    vec2.resize(10);
    fill_n(vec2.begin(),10,0);
    cout<<vec2[5];
    
    return 0;
}
