#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

#define length 15

void sort(int *);
int memQ(int *,int);

int main()
{
	std::ifstream testconditions;
	std::ifstream sample;
	std::ifstream keys;
	std::ofstream membershipQuery;
	testconditions.open("testcondition.txt",std::fstream::in);
	sample.open("sample.txt",std::fstream::in);
	keys.open("keys.txt",std::fstream::in);
	membershipQuery.open("memQ_algorithm1.txt",std::fstream::out);
	int no_of_testcases,array[length],key,i,j,element,Query;
	testconditions>>no_of_testcases;
	for(i=0;i<no_of_testcases;i++)
	{
		Query=0;
		keys>>key;
		for(j=0;j<length;j++)
		{
			sample>>element;
			array[j]=element;
		}	
		sort(array);
		Query=memQ(array,key);
		membershipQuery<<Query<<std::endl;
	}
	sample.close();
	keys.close();
	testconditions.close();
	membershipQuery.close();
	return 0;
}

void sort(int *b)
{
	int i,j,temp,pos;
	for (i=0;i<(length-1);i++)
	{	
		pos=i; 
		for(j=i+1;j<length;j++)
		{
			if ( *(b+pos)>*(b+j))
				pos=j;
		}
		if(pos!=i)
		{
			temp=*(b+i);
			*(b+i)=*(b+pos);
			*(b+pos)=temp;
		}
	}
}

int memQ(int *b,int key)
{
	int first,last,mid,Query;
	first=3;			//error injected :: Original : first=0;
	last=length-1;
	mid=(first+last)/2;
	while (first<=last) 
	{
		if (*(b+mid)<key)
			first = mid+1;    
		else if (*(b+mid)==key) 
		{
			Query=1;
			break;
		}
		else
			last=mid-1;
			mid=(first+last)/2;
	}
	if (first>last)
		Query=0;
	return Query;
}
