#include "tree.h"
#include <iostream>
#include <queue>
int main()
{
	int lower,upper;
	queue< node* > q;

	cin>>lower>>upper;
	node* root=init_tree();
	node* cur=root;
	q.push(root);
	while(!q.empty()){
		cur=q.front();q.pop();
		if(cur->val >upper){ 
				if(cur->left)  q.push(cur->left);continue;
		}
		else if(cur->val < lower){ if(cur->right) 
										q.push(cur->right);continue;}
		else { 	cout<<cur->val<<",";
				if(cur->left)  q.push(cur->left);
				if(cur->right) q.push(cur->right);
		}
	}
}
