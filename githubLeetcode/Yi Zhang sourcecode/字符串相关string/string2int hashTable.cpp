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
void main(void)   
{   
	string t;
	while(cin>>t){
		unsigned h=hash(t);
		node* p;
		for(p=bin[h];p!=NULL;p=p->next){
			if(p->word==t){
				p->count++;
				break;
			}
		}
		if(p==NULL){
			p=new node();
			p->word=t;
			p->next=bin[h];
			p->count=1;
			bin[h]=p;
		}
	}
} 