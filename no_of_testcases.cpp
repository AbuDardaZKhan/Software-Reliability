#include<iostream>
#include<fstream>

int main()
{
	std::ofstream testconditions;
	int data;
	testconditions.open("testcondition.txt");
	std::cout<<"How many testcases do you want to develop?"<<std::endl;
	std::cin>>data;
	testconditions<<data<<std::endl;
	return 0;
}
