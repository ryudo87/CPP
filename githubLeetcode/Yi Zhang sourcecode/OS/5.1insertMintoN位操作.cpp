#include "stdafx.h"
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
#include <list>
#include <memory>
#include <ctime>
using namespace std;

int insertMtoN(int N,int M,int i,int j)
{
	if(i>j) return -1;

	int mask=1;
	for(int count=0;count<j-i;++count){
		mask<<=1;
		mask|=1;
	}
	mask<<=i;
	mask=~mask;
	N&=mask;
	
	M<<=i;
	int res=N|M;
	cout<<hex<<res;
	return res;
}
int main()
{
	insertMtoN(0x400,0x13,2,6);
	return 0;
}


