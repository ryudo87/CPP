
#include "stdafx.h"
#include <iostream>
#include <string>
//#include "ListNode.h"
#include <vector>
#include <cstdio>
using namespace std;

void exchange(vector<int>::iterator p1,	vector<int>::iterator p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	 vector<int> color;
	int i;
	while(cin>>i)
	{
		color.push_back(i);
	}
	
	vector<int>::iterator begin=color.begin();
	vector<int>::iterator end=color.end()-1;
	vector<int>::iterator current=color.begin();

	while(current<end)
	{
		if(*current==0){
			exchange(current,begin);
			current++;
			begin++;
		}
		else if(*current==1)
			current++;
		else{
			exchange(current,end);
			current++;
			end--;
		}
	}

	for(vector<int>::size_type i=0;i<color.size();i++)
	{
		cout<<color[i]<<",";
	}

	
}

