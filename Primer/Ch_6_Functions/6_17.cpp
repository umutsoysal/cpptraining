#include <iostream>
#include <string>

bool hasCapital(const std::string s){

    for (auto &c :s)
        if(c>='A' && c<= 'Z')
            return true;
    return false;
}


void toLowerStr(std::string &s){

    for (auto &c:s)
        if (c>='A' && c<='Z')
            c= c- ('A'-'a');
}





int main(){

    std::string str("Hello World");

    std::cout<<hasCapital("Abc")<<" "<<hasCapital("abc")<<hasCapital(str)<<std::endl;

    toLowerStr(str);
    
    std::cout<<str<<std::endl;
    
    return 0;
}
