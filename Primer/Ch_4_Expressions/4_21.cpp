

#include <iostream>
#include <vector>



int main(){

std::vector<int> v;  // Define a vector

int i;

while(std::cin>>i)
	v.push_back(i); // Read the entries as vector elements

for (auto &elem: v)
	elem=elem %2 ? elem*2 : elem;

for (const auto &elem: v)
	std::cout<< elem << " ";
std::cout<<std::endl;





	return 0;
}