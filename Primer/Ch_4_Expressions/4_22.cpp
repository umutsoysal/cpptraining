// This script shows the usage of conditional operator
// It is an alternative to if experession however it is less readable.

#include <iostream>
#include <vector>



int main(){

std::vector<int> v;  // Define a vector
int grades;
int i;

while(std::cin>>grades){
	std::cout<< ((grades<60)? "fail" : (grades>75) ? "high pass" : "pass")<<std::endl;
}
	return 0;
}

