// Write a program using the series of if statements to count the number of wovels in text read from cin




#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
	unsigned acount=0,bcount=0,ccount=0;
	char ch;
	while(std::cin>>ch){
		if (ch=='a')
			++acount;

	}

	std::cout<<acount<< std::endl;

	return 0;
}
