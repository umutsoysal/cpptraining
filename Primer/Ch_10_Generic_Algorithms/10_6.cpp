
// Using fill_n, write a program to set a sequence of int values to 0.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int>pre={0,12,45,87,65,78,};
    cout<<pre<<endl;
    fill_n(pre.begin(),pre.size(),0);
    cout<<pre<<endl;
    return 0;
}
