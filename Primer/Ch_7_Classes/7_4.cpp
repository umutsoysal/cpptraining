

// A class names person for subsequent exercices

#include <string>

struct  Person
{
	std::string name;
	std::string address;

	std::string getName() const {return name;}
	std::string	getAddress() const{return address;}
};

int main(){

	return 0;
}