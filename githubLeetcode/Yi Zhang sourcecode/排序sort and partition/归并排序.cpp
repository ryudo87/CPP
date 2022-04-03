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

int oldarr[]={1};
vector<int> arr(oldarr,oldarr+1);
void myMerge(	int first1,  int last1,	int first2,int  last2 )
{
	int oldfirst=first1;
	vector<int> tempArr;
	while(first1<=last1 && first2<=last2)
	{
		if(arr[first1]<arr[first2])
			tempArr.push_back(arr[first1++]);
		else
			tempArr.push_back(arr[first2++]);
	}
	if(first1<=last1)
		tempArr.insert(tempArr.end(),arr.begin()+first1,arr.begin()+last1+1);
	if(first2<=last2)
		tempArr.insert(tempArr.end(),arr.begin()+first2,arr.begin()+last2+1);

	copy(tempArr.begin(),tempArr.end(),arr.begin()+oldfirst);//////

}
void merge_sort(int first, int last)
{
	if(first>=last) return;
	merge_sort(first, (last+first)/2);
	merge_sort(	(last+first)/2+1,last	);

	myMerge(	first, (last+first)/2,	(last+first)/2+1,last	);
}
int _tmain(int argc, _TCHAR* argv[]) 
{

	merge_sort(0,arr.size()-1);
	//ostream_iterator<int> os(cout, " ");
	copy(arr.begin(),arr.end(),ostream_iterator<int> (cout, " "));
	return 0;
}

