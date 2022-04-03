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

		if(0==i) continue;
		if(2*i+2<vec.size())
			vec[i].right=&vec[2*i+2];
	}

}
//method1:
bool cover(node* root,node* p)
{
	if(p==root) return true;
	if(root==NULL) return false;
	return cover(root->left,p)||cover(root->right,p);
}
node* commonAncestor1(node* root,node* p,node* q)
{
	if(cover(root->left,p)&&cover(root->left,q))
		return commonAncestor1(root->left,p,q);
	if(cover(root->right,p)&&cover(root->right,q))
			return commonAncestor1(root->right,p,q);

	return root;
}
////////////////////////////////////////////////////
//method2:
	static int TWO_NODES_FOUND = 2;
	static int ONE_NODE_FOUND = 1;
	static int NO_NODES_FOUND = 0;

 // Checks how many ¡°special¡± nodes are located under this root
 int covers(node* root, node* p, node* q)
 {
	 int ret = NO_NODES_FOUND;
	 if (root == NULL) return ret;
	 if (root == p || root == q) ret += 1;
	 ret += covers(root->left, p, q);
	 if(ret == TWO_NODES_FOUND) // Found p and q
	 return ret;
	 return ret + covers(root->right, p, q);
 }

 node* commonAncestor(node* root, node* p, node* q)
 {
	 if (q == p && (root->left == q || root->right == q))
		 return root;
	 int nodesFromLeft = covers(root->left, p, q); // Check left side

	 if (nodesFromLeft == TWO_NODES_FOUND)
	 {
		 if(root->left == p || root->left == q) return root->left;
		 else return commonAncestor(root->left, p, q);
	 }
	 else if (nodesFromLeft == ONE_NODE_FOUND)
	 {
		 if (root == p) return p;
		 else if (root == q) return q;
	 }
	 int nodesFromRight = covers(root->right, p, q); // Check right side
	 if(nodesFromRight == TWO_NODES_FOUND)
	 {
		 if(root->right == p || root->right == q) return root->right;
		 else return commonAncestor(root->right, p, q);
	 }
	 else if (nodesFromRight == ONE_NODE_FOUND)
	 {
		 if (root == p) return p;
		 else if (root == q) return q;
	 }
	 if (nodesFromLeft == ONE_NODE_FOUND &&
			 	 nodesFromRight == ONE_NODE_FOUND)
		 return root;
	 else return NULL;
}

int main()
{
	init();
	node* res=commonAncestor(&vec[0],&vec[3],&vec[4]);

	cout<<res->name<<endl;

	return 9;
}




