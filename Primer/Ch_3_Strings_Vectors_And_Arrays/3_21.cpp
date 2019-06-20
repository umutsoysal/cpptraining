// ITERATOR OPERATIONS


#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;


// Maybe we can use templates to reduce two function with a single type T 

void print_vector_int(vector<int> &v){
    for (auto it=v.begin(); it!=v.end(); ++it)
        std::cout << *it << " ";
    std::cout<<std::endl;
} 

void print_vector_string(vector<string> &v){
    for (auto it=v.begin(); it!=v.end(); ++it)
        std::cout << *it << " ";
    std::cout<<std::endl;
} 





int main(){

    
    vector<int> v1;            // empty vector
    vector<int>v2(10);         // 10 elements with 0 value
    vector<int>v3(10,42);      // 10 elemements initialized to 42
    vector<int>v4{10};         // Single element initialized to 10
    vector<int>v5{10,42};      // 2 elements, 10 and 42
    vector<string>v6{10};      // 10 elements of char, initialized to zero
    vector<string>v7{10,"hi"}; // 10 elements initialized to "hi"



    print_vector_int(v1);
    print_vector_int(v2);
    print_vector_int(v3);
    print_vector_int(v4);
    print_vector_int(v5);
    print_vector_string(v6);
    print_vector_string(v7);

    

    return 0;

}

