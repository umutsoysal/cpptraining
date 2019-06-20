// ITERATOR OPERATIONS


#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;



int main(){


    vector<string>text;

    string line;

    while(getline(std::cin,line)){
        text.push_back(line);
        if (text.size()>5)
                    break;
    }

    for (auto it=text.begin(); it!=text.end() && !it-> empty(); ++it)
        for (auto &c :*it)
            c=toupper(c);

    for (auto &elem : text)
        if (elem.empty())
            std::cout<<std::endl;
        else
            std::cout<<elem<<" ";

    
    

    return 0;

}

