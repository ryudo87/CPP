#include <cstdio>
#include <stack>
using namespace std;
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
}node;

node* init_tree()
{
	node* root=(node*)malloc(sizeof(node));
	if(!root) return root;
	root->val=3;
	
	node* cur=(node*)malloc(sizeof(node));
	cur->val=1;
	cur->left=NULL;
	cur->right=NULL;
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
	
	return root;
}
node* transform_bst_to_linklist(node* root)
{
stack<node*> sta;
//sta.push(root);
node* cur=root;
node* head=NULL;
node* last=NULL;
	while(!sta.empty() || cur)
	{
		while(cur){
			sta.push(cur);
			cur=cur->left;
		}
		cur=sta.top();sta.pop();
		
		if(last){ last->right=cur;}
		else {head=cur;}
		cur->left=last;

		last=cur;cur=cur->right;
	}
	
	
return head;
}

int main()
{
	node* root=init_tree();
	root=transform_bst_to_linklist(root);
	while(root){printf("%d,",root->val);root=root->right;}
	return 0;
}
