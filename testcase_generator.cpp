#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

#define length 15

int main()
{
	std::ifstream testconditions;
	std::ofstream sample;
	std::ofstream keys;
	testconditions.open("testcondition.txt",std::fstream::in);
	sample.open("sample.txt",std::fstream::out);
	keys.open("keys.txt",std::fstream::out);
	int no_of_testcases,array_element,key,i,j;
	testconditions>>no_of_testcases;
	srand(time(NULL));
	for(i=0;i<no_of_testcases;i++)
	{
		for(j=0;j<length;j++)
		{
			array_element=rand()%100;
			sample<<array_element<<std::endl;
		}
		//sample<<std::endl;
		key=rand()%100;
		keys<<key<<std::endl;
	}
	sample.close();
	keys.close();
	testconditions.close();
	return 0;
}
