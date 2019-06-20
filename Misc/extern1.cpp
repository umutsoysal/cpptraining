
#include <iostream>
#include "global.h"

int b=50; 
extern int anotherglobal;

int main() {

	int a=100; //Defined at local scope

	std::cout<<a<<std::endl;

	std::cout<<b<<std::endl;

	std::cout<<myglobalInt<<std::endl;

	std::cout<<anotherglobal<<std::endl;

	return 0;
}