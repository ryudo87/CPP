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

void* align_alloc(int size,int align)
{
	if(size<=0) return NULL;
	if(align&(align-1)) return NULL;
	void* p=malloc(size+align-1+sizeof(void*));
	if(p==NULL) return NULL;

	cout<<hex<<p<<endl;
	cout<<hex<<align<<endl;

	cout<<"p+size+align-1 :"<<hex<<((size_t)p+size+align-1)<<endl;
	
	void** pp=(void**)(((size_t)p&(~(align-1)))+align);
	cout<<"(pp)"<<(pp)<<endl;
	pp[-1]=p;
	cout<<"pp[-1]:"<<hex<<pp[-1]<<endl;
	cout<<"pp%align:"<<((size_t)pp%align)<<endl;
	return pp;
}
void align_free(void* p)
{
	if(p==NULL) return;
	void** pp=(void**)p;
	cout<<"pp[-1]"<<hex<<pp[-1]<<endl;
	/*void* p=(void*)cp[-1];*/
	free(pp[-1]);

}

void MemCopy(const void* from,void* to,int n)
{
	assert(from!=NULL);
	assert(to!=NULL);
	assert(n>0);
	const char* pfrom=(const char*) from;
	char* pto=(char*)to;

	//需要从后往前拷贝
	if(pfrom<pto && pfrom+n>pto){
		for(int i=n-1;i>=0;--i){
			pto[i]=pfrom[i];
		}
	}
	else{
		for(int i=0;i<n;++i){
			pto[i]=pfrom[i];
		}
	}
}
void main(void){
	int arr[]={0,1,2,3,4,5,6,7,8};
	MemCopy(arr,arr+3,8);
	for(int i=0;i<9;++i) cout<<arr[i]<<","; cout<<endl;
	MemCopy(arr,arr+3,24);
	for(int i=0;i<9;++i) cout<<arr[i]<<","; cout<<endl;
	MemCopy(arr+1,arr,8);
	for(int i=0;i<9;++i) cout<<arr[i]<<","; cout<<endl;
	MemCopy(NULL,arr,8);
	MemCopy(NULL,arr,-7);
	MemCopy(arr,NULL,8);

	/*void* w=align_alloc(1000,64);
	cout<<endl;
	align_free(w);*/
}