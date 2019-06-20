// this script creates a vector of 10 elements and doubles their value by using an iterator


#include <iostream>
#include <vector>


using std::vector;

void sum_adjacent(const std::vector<int> &v){

    if (v.size()<2)
                return;
    for (auto it=v.cbegin(); it !=v.cend()-1;++it)
        std::cout<<*it+*(it+1)<< '\t';
    std::cout<<std::endl;
}



int main(){


    vector<int>v; // empty vector
    int i;
    while (std::cin>>i)
        v.push_back(i);

    sum_adjacent(v);
        
             
    return 0;

}

