#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <list>
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
#define N 3
typedef unsigned char byte;


void printBinary(unsigned k)
{	string bi;
	if(k==0) cout<<"0"<<endl;
	for(int i=0;i<sizeof(k);++i){
		for(int j=0;j<8;++j)
		{
			if(k&1)	bi.insert(0,"1");
			else bi.insert(0,"0");
			k>>=1;
		}
		bi.insert(0,",");
	}
	cout<<bi<<endl;
}

void reverse_bits(unsigned int v)
{
	printBinary(v);
	v=((v>>1)&0x55555555)|((v&0x55555555)<<1);
	printBinary(v);
	v=((v>>2)&0x33333333)|((v&0x33333333)<<2);
	printBinary(v);
	v=((v>>4)&0x0F0F0F0F)|((v&0x0F0F0F0F)<<4);
	printBinary(v);
	v=((v>>8)&0x00FF00FF)|((v&0x00FF00FF)<<8);
	printBinary(v);
	v=(v>>16)|(v<<16);
	printBinary(v);
}

void reverse_bits2(unsigned int v)
{
	 unsigned int s = sizeof(v) * 8; // bit size; must be power of 2 
	 unsigned int mask = ~0;         
	 while ((s >>= 1) > 0) 
	 {
	   printBinary(mask);
	   mask ^= (mask << s);
	   printBinary(mask);
	   printBinary(v);
	   v = ((v >> s) & mask) | ((v << s) & ~mask);
	   printBinary(v);
	 }
}
void main(void)   
{
	reverse_bits2(2328573);
}

