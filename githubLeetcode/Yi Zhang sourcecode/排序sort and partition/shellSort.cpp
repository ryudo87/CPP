#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <list>
#include <memory>
using namespace std;


int arr[]={8,8,3,4,1,-1,8,10};

void shell_sort()
{
	int len=8;
	int insertNum;
	int gap=len/2;
	while(gap)
	{
		for(int i=gap;i<len;i++)
		{
			insertNum=arr[i];
			int j=i;
			while(j>=gap&&insertNum<arr[j-gap])
			{
				arr[j]=arr[j-gap];
				j-=gap;
			}
			arr[j]=insertNum;
		}
		gap=gap/2;
	}
}
int _tmain(int argc, _TCHAR* argv[]) 
{
	shell_sort();

	ostream_iterator<int> os(cout, " ");
	copy(arr,arr+8,os);
	return 0;
}

