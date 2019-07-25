#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>


using namespace std;

int main(){

    cout<<"hello"<<endl;
    int val=42;

    vector<int>vec {10, 12,32,42,52};
    
    auto result=find(vec.cbegin(),vec.cend(), val);

    //cout<<vec[1]<<endl;
    cout<<"The value " <<val << (result==vec.cend()? " is not present" : " is present")<<endl;


    // search in strings
    string value="GAN"; //search for this literal

    list <string> lst={"CNN","DRL","GAN"};
    
    auto result2=find(lst.cbegin(),lst.cend(),value);

    cout<<"The value " <<value << (result2==lst.cend()? " is not present" : " is present")<<endl;
    
    ;

    // search with pointers

    int ia[]={27,210,12,47,109,55,83};

    int val2=83;

    int* result3=find(begin(ia),end(ia),val2);

    cout<<"The value " << val2 << (result3==end(ia)? " is not present" : " is present")<<endl;

    auto result4=find(ia+1,ia+4,val2);

    cout<<"The value " << val2 << (result4==ia+4? " is not present in the subrange" : " is present in the subrange")<<endl;
    

    // Read only algoritmhs

    int sum=accumulate(vec.cbegin(),vec.cend(),0);
    cout<<"accumulated sum is: "<<sum<<endl;


    //Algorithms that operate on two sequences

    list<string> cities1={"Istanbul","Paris","Pittsburgh","Boston"};

    list<string> cities2={"Istanbul","Paris","Pittsburgh","Boston","Newyork"};
      
    bool city= equal(cities1.cbegin(),cities1.cend(),cities2.cbegin());

    cout<<"Cities are same "<<city<<endl;
    
    return 0;

    
}
