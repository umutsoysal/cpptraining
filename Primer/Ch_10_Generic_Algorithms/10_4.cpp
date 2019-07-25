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

    vector<double>vec {10, 12,32,42,52};
    

    // Read only algoritmhs

    int sum=accumulate(vec.cbegin(),vec.cend(),0);
    cout<<"accumulated sum is: "<<sum<<endl;


    return 0;

    
}
