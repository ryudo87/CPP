
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <set>
using namespace std;

//一个binary tree，逆序打印BFS序列。不能同时用两段存储空间（不同时用queue和stack）
struct node
{
	int num;
	node* left;
	node* right;
	node* parent;
	node(int i)
	{
		num=i;
		left=NULL;
		right=NULL;
	}
};
void print_reverse_BFS()
{
	node* root=new node(0);
	node *left, *right, *cur;
	stack<node*> sta;
	sta.push(root);

	for(int i=1;i<8;i+=2){
		cur=sta.top();
		sta.pop();
		left=new node(i);
		right=new node(i+1);
		cur->left=left;
		cur->right=right;
		left->parent=cur;
		sta.push(left);
		sta.push(right);
	}



	vector<node* > vec;
	unsigned index=0;
	vec.push_back(root);
	while(index<vec.size()){
		cur=vec[index++];
		if(cur->left)
			vec.push_back(cur->left);
		if(cur->right)
			vec.push_back(cur->right);
	}

	for(vector<node* >::reverse_iterator it=vec.rbegin();it!=vec.rend();it++)
	{
		cout<<(*it)->num;
	}

}



