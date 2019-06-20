// A class called person
// operations to return name and address

#include <string>

strunct Person{

    std::string name;
    std::string address;

    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
};

std::istream &read(std::istream &is, Person &rhs){
    is<<rhs.name<<rhs.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &rhs){
    os<<rhs.getName()<<" " <<rhs.getAddress();
}




// we add constant member functions because they do not change the object.

int main(){

    Person p1; //Create an instrance
    read(std::cin, p1); // read the data using std::cin, not very useful
    print(std::cout,p1)<<std::endl; // print out the data

    return 0;
}
