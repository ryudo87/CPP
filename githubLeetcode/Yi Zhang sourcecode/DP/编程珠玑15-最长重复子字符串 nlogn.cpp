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
#define NHASH 5
#define MULT 31

struct node{
	string word;
	int count;
	node* next; 
};
node* bin[NHASH];
unsigned hash(string str)
{
	unsigned h=0;
	for(size_t i=0;i<str.size();i++)
		h=MULT*h+str[i];
	return h%NHASH;
}
typedef char* charptr;
int pstrcmp(const void* p1,const void* p2)
{
	return strcmp( *(char**)p1,*(char**)p2);
}
int comlen(char *p,char* q)
{
	int i=0;
	while(*p&&(*p++==*q++))	i++;
	return i;
}
void main(void)   
{   
	char ptr[]="Ask not what your country can do for you ask what you can do for your country";
	char t[]="banana";
	int N=strlen(ptr);
	charptr *a=new charptr[N];
	for(int i=0;i<N;++i){
		a[i]=ptr+i;
	}
	qsort(a,N,sizeof(char*),pstrcmp);

	int maxlen=0,maxi=0;
	for(int i=0;i<N-1;++i){
		int tmp=0;
		if( (tmp=comlen(a[i],a[i+1]))  >maxlen){
			maxlen=tmp;
			maxi=i;
		}	
	}
	printf("%d,%.*s\n",maxlen,maxlen,a[maxi]);

}