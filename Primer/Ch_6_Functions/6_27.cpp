#include <initializer_list>
#include <iostream>


int sumInTheList(std::initializer_list<int> il){

    int sum=0;

    for (auto &e : il)
        sum+=e;
    return sum;
}


int main(){

    std::cout<<sumInTheList({1,2,3,4,5,6,7,8,9,10})<<std::endl;
    
    return 0;
}
