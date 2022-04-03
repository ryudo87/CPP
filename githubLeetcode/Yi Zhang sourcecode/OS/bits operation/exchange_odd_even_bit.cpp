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
#include <hash_set>
#include "tree.h"
using namespace std;

void printBinary(int k)
{	string bi;
	if(k==0) cout<<"0"<<endl;
	while(k){
		if(k&1)	bi.insert(0,"1");
		else bi.insert(0,"0");
		k>>=1;
	}
	cout<<bi<<endl;
}
int exchange_odd_even_bit(int x)
{
	return (x>>1)&(0x55555555) | (x<<1)&(0xaaaaaaaa) ;
}
void main()  
{ 
	int x=33;
	printBinary(x);
	printBinary(exchange_odd_even_bit(x));
}  