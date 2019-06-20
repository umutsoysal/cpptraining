// this script creates a vector of 10 elements and doubles their value by using an iterator


#include <iostream>
#include <vector>



using std::vector;




int main(){


    vector<int>v; // empty vector
    for (int i=0; i!=10; ++i){
             std::cin>>i;
             v.push_back(i);
    }
    for (auto it=v.begin();it!=v.end();++it)
        *it *= 2;
    for(const auto &elem: v)
        std::cout<<elem<< " ";
    std::cout<<std::endl;
             
    return 0;

}

