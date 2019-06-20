// A function to calculate the factorial of a given integer

#include <iostream>

int fact(int n){

    if (n<1){
        std::cout<<" n should be larger then 1!"<<std::endl;
        return n;
    }
    int ans=n;
    while (--n)
        ans=ans*n;

    return ans;
}

    


int main(){

    int n;
    std::cout<<"Type an integer to calculate its factorial!: ";
    std::cin>>n;
    std::cout<<n<<"!="<<fact(n)<<std::endl;


    return 0;
}
