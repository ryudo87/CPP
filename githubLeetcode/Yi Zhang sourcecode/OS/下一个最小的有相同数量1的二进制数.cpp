#include "stdafx.h"
#include <cstdio>
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

//class Tool
//{
//	void init(){}
//	
//public: 
//	//virtual void type()=0;
//	virtual void Action(){}
//	string Name(){return typeid(*this).name();}
//
//};
//
//
//int getMaxDepth(Node* root)
//{
//	int dep=0;
//	
//	
//	return dep;
//}
//int main(int argc, _TCHAR* argv[])
//{
//	Node n6(6);
//	Node n5(-2,NULL,&n6);
//	Node n4(2);
//	Node n3(-4,NULL,&n5);
//	Node n2(1,&n4);
//	Node n1(3,&n3);
//	Node n0(2,&n1,&n2);
//	
//	stack<int> st;
//	
//
//	return 0;
//}
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
void print_next_smallest_and_prev_largest_number(int old)
{
	if(0==old) return;
	//10,0110
	printBinary(old);
	int countOne=0;
	int mask=1;
	while(1){
		if(old&mask){
			countOne++;
		}
		else {
			if(countOne>0)
				break;
		}
		mask=mask<<1;
	}

	old|=mask;//10,1110
	printBinary(old);
	old&=~(mask-1);//10,1000
	printBinary(old);
	mask=(1<<(countOne-1))-1;
	old|=mask;//10,1001
	
	cout<<"next_smallest:";
	printBinary(old);
}


void main(void)
{
	print_next_smallest_and_prev_largest_number(0x17);

}