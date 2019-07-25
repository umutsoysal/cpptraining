#include <iostream>
#include "dummy_feature_def.hpp"



int main(){

    std::cout<<"Addres of first class pointer!"<<std::endl;

    Dummy_UseFeature(Boston);

    std::cout<<"address of second class pointer!"<<std::endl;

    Dummy_UseFeature(Istanbul);

    std::cout<<"address of third class pointer"<<std::endl;
    


    int *a;

    std::cout<<a<<std::endl;
    
   
    std::cout<<"link error problem, fix it!"<<std::endl;

    return 0;

}

