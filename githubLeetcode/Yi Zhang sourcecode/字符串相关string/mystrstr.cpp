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
struct node
{
	char name;
	int data;
	struct node* left;
	struct node* right;
	node(int i):left(0),right(0),data(i){}
};
int pre[]={3};
int in[]={ 3};
void construct(int prefirst,int prelast,int infirst,int inlast,node* &root)
{
	if(prefirst>prelast||infirst>inlast)
			return;
	root=new node(pre[prefirst]);

	if(prefirst==prelast||infirst==inlast)
		return;
	int i=infirst;
	while(in[i]!=pre[prefirst])	++i;
	construct(prefirst+1,prefirst+i-infirst,infirst,i-1,root->left);
	construct(prefirst+i-infirst+1,prelast,i+1,inlast,root->right);
}

const char* mystrstr(const char* src,const char* dst)
{
	if(!src||!dst) return NULL;
	const char *begin=src, *p1=src, *p2=dst;
	while(*p1&&*p2){
		if(*p1==*p2){ p1++;p2++; }
		else{ p2=dst;p1=++begin;}

	}
	if(!*p2) return begin;
	
	return NULL;
}

int main()
{
	const char* t= mystrstr("baabcabd",NULL);
	return 0;
}


