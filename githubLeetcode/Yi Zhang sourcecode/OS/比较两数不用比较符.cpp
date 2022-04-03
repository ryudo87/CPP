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

int flip(int bit){
	return 1^bit;}
int getsign(int t){	
	return flip((t>>31)&1);
}
int get_max(int a,int b)
{
	int sa=getsign(a);
	int sb=getsign(b);
	int sc=getsign(a-b);
	int ta=sa^sb;
	int tc=flip(ta);
	int k=ta*sa+tc*sc;
	int q=flip(k);

	return a*k+b*q;
}
int main()
{
	unsigned w=-1;
	int a=-496729588,b=-496729588;
	//cout<<a<<endl;
	cout<<get_max(a,b);
	return 0;
}


