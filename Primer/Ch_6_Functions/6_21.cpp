#include <iostream>

int largerInt(int a, int *pb)
{
    return a>*pb ? a : *pb;
}

int main(){
                                   \
    int larger;
    int a=5;
    int b=10;
    int *pb=&b;
    larger= largerInt(a,pb);
    std::cout<<larger<<std::endl;
    
    return 0;
}
