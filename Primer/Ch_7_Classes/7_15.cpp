// A class called person
// operations to return name and address

#include <string>
#include <iostream>

struct Person{

    Person()=default; // Default constructor
    Person( const std::string &n) : name(n){}
    Person (const std::string &n, const std::string &a) : name(n), address(a) {}
    Person(std::istream &is );
           
    
    std::string name;
    std::string address;

    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
};

std::istream &read(std::istream &is, Person &rhs){
    is>>rhs.name>>rhs.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &rhs){
    os<<rhs.getName()<<" " <<rhs.getAddress();
    return os;
}

Person::Person(std::istream &is){
    read(is, *this);
}

// we add constant member functions because they do not change the object.

int main(){

    Person p1; //Create an instrance
    Person p2("Umut Soysal");
    Person p3("Umut Soysal", "ArdenStreet");
    Person p4(std::cin);

    print(std::cout, p1) << std::endl;
    print(std::cout, p2) << std::endl;
    print(std::cout, p3) << std::endl;
    print(std::cout, p4) << std::endl;

    
    return 0;
}
