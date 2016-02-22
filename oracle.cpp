#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

#define length 15

int main()
{
	std::ifstream testconditions;
	std::ifstream memQ_reference;
	std::ifstream memQ_algorithm1;
	testconditions.open("testcondition.txt",std::fstream::in);
	memQ_reference.open("memQ_reference.txt",std::fstream::in);
	memQ_algorithm1.open("memQ_algorithm1.txt",std::fstream::in);
	int Query_reference,Query_algorithm1,i,no_of_testcases,failure=0;
	testconditions>>no_of_testcases;
	for(i=0;i<no_of_testcases;i++)
	{
		memQ_reference>>Query_reference;
		memQ_algorithm1>>Query_algorithm1;
		if(Query_reference!=Query_algorithm1)
			failure++;
	}
	std::cout<<"Number of failures in test algorithm with respect to reference algorithm : "<<failure<<std::endl;
	memQ_reference.close();
	memQ_algorithm1.close();
	testconditions.close();
	return 0;
}
