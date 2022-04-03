//Find the vertical sum in a binary tree.
//Input:
//(Plz construct the tree using the pre-order and in-order traversals)
//Pre-order: 1 2 4 5 3 6 7
//In-order: 4 2 5 1 6 3 7
//Output:
//Arr-Index Sum
//0 4
//1 2
//3 12
//4 3
//5 7
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

map<int,int> col_sum;
void vertical_sum(node* T,int column)
{
	if(!T) return;

	if(col_sum.find(column)==col_sum.end())
		col_sum[column]=T->data;
	else col_sum[column]+=T->data;

	vertical_sum(T->left,column-1);
	vertical_sum(T->right,column+1);
}
int main()
{

	stack<node> s1,s2;
	vector<node> vec;
	for(int i=0;i<6;i++)
	{
		node tmp={'A'+i,i,NULL,NULL};
		vec.push_back(tmp);
	}
	for(size_t i=0;i<(vec.size())/2;i++)
	{
		vec[i].left =&vec[2*i+1];

		if(2*i+2<vec.size())
			vec[i].right=&vec[2*i+2];
	}

	vertical_sum(&vec[0],0);

	for(map<int,int>::iterator it=col_sum.begin();it!=col_sum.end();it++)
	{
		cout<<it->first<<","<<it->second<<endl;
	}

	//	bool fromLeft=true;
	//	s1.push(vec[0]);
	//	while()
	return 9;
}




