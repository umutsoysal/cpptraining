#include <iostream>

void reset(int *ip)
{
    *ip=0;
     ip=0;
}


int main(){
    int n=0, i=42;
    int *p=&n, *q=&i;
    std::cout<<*p<<std::endl;
    *p=42;
    p=q;
    i=42;
    reset(&i);
    std::cout<<"i = " << i << std::endl;
    return 0;
}
