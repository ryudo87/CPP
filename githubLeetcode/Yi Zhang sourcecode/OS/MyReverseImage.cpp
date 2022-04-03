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
#include <ctime>
using namespace std;
#define BYTE unsigned char
void swap(BYTE &a, BYTE &b)
{
	a^=b;
	b^=a;
	a^=b;
}
void reverse_BYTE(BYTE &byte)
{
		BYTE ret=0;
		
		for(int i=0;i<8;i++)
		{
		   ret <<= 1;
		   ret |= byte & 1;
		   byte >>=  1;
		}
		byte=ret;
}
void reverse_image(BYTE bitmap[], int x, int y)//x is row num, and y is the width
{

	if(y%8!=0) {
		cerr<<"width is not a multiple of 8 pixels"<<endl;
		return;
	}
	if(x<=0||y<=0){ 
		cerr<<"invalid dimension"<<endl;
		return;
	}

	if(!bitmap){
		cerr<<"empty array"<<endl;
		return;
	}

	const unsigned int arrSize=x*y/8;
	const unsigned int groupSize=y/8;

	for(int i=0;i<arrSize;++i)//reverse every element first
		reverse_BYTE(bitmap[i]);

	for(int i=0;i<x;++i)
	{
		int left=i*groupSize;
		int right=(i+1)*groupSize-1;
		for(;left<right;left++,right--)
			swap(bitmap[left], bitmap[right]);
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	BYTE arr[]={{128},{64},{32},{16}};
	cout<<sizeof(arr)<<endl;
	reverse_image(arr, 2, 16);
	//reverse_image(arr, 1, 24);
	//reverse_image(arr, 4, 8);
	//reverse();

	cout<<sizeof(BYTE)<<endl;
	return 0;
}


