#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <deque>
#include <memory>
#include <ctime>
#include <typeinfo>
using namespace std;

int arr[]={0,1,2,2,2,5};
void find_magic_index(int i,int j)
{
		if(i>j) return;
		int mid=(i+j)/2;
		if(arr[mid]==mid) {cout<<mid<<endl;}
		{
			int leftend=min(mid-1,arr[mid]);
			int rightend=max(mid+1,arr[mid]);
			find_magic_index(i,leftend);
			find_magic_index(rightend,j);

		}

}
void main(void)   
{   
	find_magic_index(0,5);
	
}