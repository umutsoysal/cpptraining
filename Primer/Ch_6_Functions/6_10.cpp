//This function swaps two integers

#include <iostream>

void swapint(int *a, int *b){

    int temp=*a;
    *a=*b;
    *b=temp;
    
}

int main(){

    int a,b;
    std::cin>>a>>b;
    swapint(&a,&b);
    std::cout<<"Swapped values :" <<a<<" "<<b<<std::endl;
    
    return 0;
}
