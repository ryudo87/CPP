
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
using namespace std;
#define Max 100;

struct node
{
	char name;
	int data;
	struct node* left;
	struct node* right;
};
stack<node> s1,s2;
vector<node> vec;
map<int,int> col_sum;
int preorder[]={1,2,4,5,3,6};
int inorder[]={4,2,5,1,6,3};

void init()
{
	for(int i=0;i<5;i++)
	{
		node tmp={'A'+i,i,NULL,NULL};
		vec.push_back(tmp);
	}
	for(size_t i=0;i<(vec.size())/2;i++)
	{

		vec[i].left =&vec[2*i+1];

		if(0==i) continue;
		if(2*i+2<vec.size())
			vec[i].right=&vec[2*i+2];
	}
}
bool isBalance=true;
int isBalancedTree(node *T, int level)
{
	if(!T) return level-1;
	int llevel=isBalancedTree(T->left,level+1);
	int rlevel=isBalancedTree(T->right,level+1);
	if(abs(llevel-rlevel)>1)
		isBalance=false;

	if(llevel>=rlevel) return llevel;
	else return rlevel;
}
int main()
{
	init();
	cout<<isBalancedTree(&vec[0],0)<<isBalance<<endl;
	return 9;
}




