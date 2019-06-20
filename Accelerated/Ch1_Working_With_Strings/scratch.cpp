#include <iostream>
#include <string>

int main(){

	std::cout<<"Please enter your first name: ";

	std::string name;

	std::cin>>name;


	std::string greeting = "Hello, "+name+ "!";  
	std::string spaces(greeting.size(), ' ');
	std::string line (greeting.size(), '*');

	std::cout<<"* "<<line<<" *"<<std::endl;
	std::cout<<"* "<<spaces<<" *"<<std::endl;
	std::cout<<"* "<<greeting<<" *"<<std::endl;
	std::cout<<"* "<<spaces<<" *"<<std::endl;
	std::cout<<"* "<<line<<" *"<<std::endl;


	const std::string exclam ="!";


	return 0;

}
