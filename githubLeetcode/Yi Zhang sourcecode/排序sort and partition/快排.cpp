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


int arr[]={8,8,3,4,1};
template<class T>
void myswap(T &left, T &right)
{
	T temp=left;
	left=right;
	right=temp;
}
template<class T>
void quickSort(int first, int last)
{
	if(first>=last) return;

	T pivot=arr[first];
	int i=first,j=last;
	

	while(i<j)
	{
		while(i<j && arr[j]>pivot) --j;
			if(i<j) myswap<T>(arr[j],arr[i++]);

		while(i<j && arr[i]<=pivot) ++i;
			if(i<j) myswap<T>(arr[j--],arr[i]);
	}

	quickSort<T>(first,i-1);
	quickSort<T>(i+1,last);
}
int _tmain(int argc, _TCHAR* argv[]) 
{
	quickSort<int>(0,4);

	ostream_iterator<int> os(cout, " ");
	copy(arr,arr+5,os);
	return 0;
}

