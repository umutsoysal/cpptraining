

// The algorithm header defines a function named count that, like find, takes a pair of iterators and a value.
// Count returns a count of how often that value appears.
//Read a sequence of ints into a vector and print the count of how many elements have a given value

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){

    vector<int>vect={1,1,2,12,34,12,45,46,12,34,12,78,32,34,78};

    int target=34;

    auto result=count(vect.cbegin(),vect.cend(),target);

    cout<<"The number "<<target<<" has been occured " <<result<<" times." <<endl;
    
    return 0;

}




