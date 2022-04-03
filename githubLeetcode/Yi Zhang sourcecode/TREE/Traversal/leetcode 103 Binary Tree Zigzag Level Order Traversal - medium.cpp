Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
 [3],
 [20,9],
 [15,7]
 ]


//1)比较简单，广度优先变一下就可以了，用一个bool记录是从左到右还是从右到左，每一层结束就翻转一下。




//2) Solution:
//This problem can be solved easily using two stacks (one called currentLevel and the other one called nextLevel). You would also need a variable to keep track of the current level’s order (whether it is left->right or right->left).
//
//You pop from stack currentLevel and print the node’s value. Whenever the current level’s order is from left->right, you push the node’s left child, then its right child to stack nextLevel. Remember a Stack is a Last In First OUT (LIFO) structure, so the next time when nodes are popped off nextLevel, it will be in the reverse order.
//
//On the other hand, when the current level’s order is from right->left, you would push the node’s right child first, then its left child. Finally, don’t forget to swap those two stacks at the end of each level (ie, when currentLevel is empty).













//Given a tree, in addition to the left and right pointer, it has a third pointer, that is set to NULL.
//Set the third pointer to a node, which will be the successor of the current node, when the tree is traversed in the zig-zag order. In other words, if we traverse the tree using this third pointer alone, then we will be traversing the tree in the zig-zag order.
//Input:
//(Plz construct the tree using the pre-order and in-order traversals)
//Pre-order: 1 2 4 5 3 6 7
//In-order: 4 2 5 1 6 3 7
//So, after the pointer is fixed, the traversal of the tree using the third pointer should give,
//1 3 2 4 5 6 7
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

}
void constructTree(int pre_begin,int pre_end,int in_begin,int in_end)
{
}
void zig_zag_traverse()
{
	bool fromLeft=true;
	s1.push(vec[0]);
	while(!s1.empty()||!s2.empty())
	{
		if(fromLeft)
		{
			node tmp=s1.top();
			s1.pop();
			if(s1.empty())	fromLeft=false;
			cout<<tmp.name<<","<<endl;
			if(tmp.right)
				s2.push(*tmp.right);
			if(tmp.left)
				s2.push(*tmp.left);
		}
		else
		{
			node tmp=s2.top();
			s2.pop();
			if(s2.empty())	fromLeft=true;
			cout<<tmp.name<<","<<endl;
			if(tmp.left)
				s1.push(*(tmp.left));
			if(tmp.right)
				s1.push(*(tmp.right));
		}
	}
}
int main()
{
	init();
	//constructTree(0,6,0,6);

	zig_zag_traverse();

	for(map<int,int>::iterator it=col_sum.begin();it!=col_sum.end();it++)
	{
		cout<<it->first<<","<<it->second<<endl;
	}


	return 9;
}




