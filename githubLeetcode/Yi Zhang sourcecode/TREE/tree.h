#include <cstdio>
#include <stack>
using namespace std;
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
    struct node* parent;
}node;

node* init_tree()
{
	node* root=(node*)malloc(sizeof(node));
	if(!root) return root;
	root->val=4;
	root->parent=NULL;
    
	node* cur=(node*)malloc(sizeof(node));
	cur->val=1;
	cur->left=NULL;
	cur->right=NULL;
    cur->parent=root;
	root->left=cur;
	
	cur=(node*)malloc(sizeof(node));
	cur->val=2;
	cur->left=NULL;
	cur->right=NULL;
	root->left->right=cur;

	cur=(node*)malloc(sizeof(node));
	cur->val=8;
	cur->left=NULL;
	cur->right=NULL;
	root->right=cur;

	cur=(node*)malloc(sizeof(node));
	cur->val=5;
	cur->left=NULL;
	cur->right=NULL;
	root->right->left =cur;
	
	cur=(node*)malloc(sizeof(node));
	cur->val=0;
	cur->left=NULL;
	cur->right=NULL;
	root->left->left=cur;
	
	cur=(node*)malloc(sizeof(node));
	cur->val=3;
	cur->left=NULL;
	cur->right=NULL;
	root->left->right->right=cur;
	return root;
}
