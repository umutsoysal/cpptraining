// Write a function that takes and returns an istream&. The function should read the stram until it hits end-of-life.
//The function should print what it reads to the standart output. Reset the stream so that it is valid before returning the stream.


#include <iostream>
#include <string>


std::istream &read(std::istream &is){
    is.clear();
    std::string str;
    while (is>>str)
        std::cout<<str<<" ";
    std::cout<<std::endl;
    is.clear();
    return is;
}



int main(){

    read(std::cin);

    return 0;
}
