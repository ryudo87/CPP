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
int pre[]={1 ,2 ,4 };
int in[]={ 4, 2, 1};
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
#define MAX 100
void Prim()
{
	int G[4][4]={{MAX,3,7,1},{3,MAX,MAX,2},{7,MAX,MAX,MAX},{1,2,MAX,MAX}};
	int nodeArr[]={0,1,2,3};int len=sizeof(nodeArr)/sizeof(nodeArr[0]);
	set<int> U(nodeArr,nodeArr+1);set<int> V(nodeArr+1,nodeArr+len);
	priority_queue<int,vector<int>,greater<int> > edgeQ;
	
	while(!V.empty())
	{	int min=MAX;
		int dst=-1,src=-1;
		for(set<int>::iterator Uit=U.begin();Uit!=U.end();++Uit)
		{
			for(set<int>::iterator Vit=V.begin();Vit!=V.end();++Vit)
			{
				if(G[*Uit][*Vit]<min){
					src=*Uit;
					dst=*Vit;
					min=G[*Uit][*Vit];
				}
			}
		}
		//add newnode to U, delete it from V
		U.insert(dst);
		V.erase(dst);
		edgeQ.push(min);
		cout<<src<<"-"<<dst<<":"<<min<<endl;
	}
}
int main()
{
	//node* root=NULL;
	//construct(0,sizeof(pre)/sizeof(int)-1,0,sizeof(in)/sizeof(int)-1,root);
	//cout<<check_tree_balance(root,0)<<endl;
	Prim();
	return 0;
}


