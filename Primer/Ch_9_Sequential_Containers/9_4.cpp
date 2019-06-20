//Write a function that takes a pair of iterators to a
//vector<int> and an int value. Look for that value in the range and return
//a bool indicating whether it was found.


#include <iostream>
#include <string>
#include <vector>
#include <list>

bool hasValue(std::vector<int>::const_iterator begin;
	)



int main()
{
	std::string str; 
	std::getline(std::cin,str);
	std::vector<int> v;

	int k;

	while (iss>k)
		v.push_back(k);
	std::cin>>k;
	std::cout<<hasValue(v.cbegin(), v.cend(),k)<<std::endl;
	/* code */
	return 0;
}