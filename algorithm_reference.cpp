#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

#define length 15

int main()
{
	std::ifstream testconditions;
	std::ifstream sample;
	std::ifstream keys;
	std::ofstream memQ;
	testconditions.open("testcondition.txt",std::fstream::in);
	sample.open("sample.txt",std::fstream::in);
	keys.open("keys.txt",std::fstream::in);
	memQ.open("memQ_reference.txt",std::fstream::out);
	int no_of_testcases,array[length],key,i,j,element,Query;
	testconditions>>no_of_testcases;
	for(i=0;i<no_of_testcases;i++)
	{
		Query=0;
		keys>>key;
		for(j=0;j<length;j++)
		{
			sample>>element;
			if(element==key)
				Query=1;
		}	
		memQ<<Query<<std::endl;
	}
	sample.close();
	keys.close();
	testconditions.close();
	memQ.close();
	return 0;
}
