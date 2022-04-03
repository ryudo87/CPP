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
int pre[]={1 ,2 ,4  ,3 ,6};
int in[]={ 4, 2, 1,6, 3};
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

void inorder_successor_and_predecessor(node* root,int target)
{
	node* cur=root;
	bool visited=false;
	stack<node*> st;
	node  *pre=NULL,*suc=NULL;
	while(cur || !st.empty())
	{
		while(cur){	
			st.push(cur);
			cur=cur->left;
		}
		cur=st.top();
		st.pop();
		if(visited==true) {cout<<"succ:"<<cur->data<<endl;return;}
		if(cur->data== target){
			if(pre) cout<<"pre:"<<pre->data<<endl;
			else cout<<"no pre:"<<endl;
			visited=true;
		}
		pre=cur;
		cur=cur->right;

	}
}
int main()
{
	node* root=NULL;
	construct(0,4,0,4,root);
	inorder_successor_and_predecessor(root,3);
	
	return 0;
}


