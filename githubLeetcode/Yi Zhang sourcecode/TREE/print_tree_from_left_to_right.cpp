#include "all.h"
#include "tree.h"

void print_deq(const deque<node*>& deq)
{
	for(deque<node*>::const_iterator it=deq.begin();it!=deq.end();++it){
		cout<< (*it)->val<<",";
	}
	cout<<endl;
}
void print_tree(node* root)
{	
	if(!root) return;
	deque<node*> deq;node* cur=root;
	//deq.push_back(root);
	set<node*> visited;
	while(!deq.empty()||cur!=NULL){
		//cur=deq.back();deq.pop_back();
		while(cur){
			deq.push_back(cur); //visited.insert(cur);
			cur=cur->left;
		}
		while(visited.find(deq.back())!=visited.end()){
			deq.pop_back();
			if(deq.empty()) return;//all paths have been printed
		}
		cur=deq.back();
		cout<<"cur:"<<cur->val<<endl;
		
		if(cur->left==NULL && cur->right==NULL)
		{
			print_deq(deq);
			deq.pop_back();
			while(visited.find(deq.back())!=visited.end()){
				deq.pop_back();
				if(deq.empty()) return;//all paths have been printed
			}
			cur=deq.back()->right;
			visited.insert(deq.back());
			
		}
		else {
			visited.insert(cur);
			cur=cur->right; 
		}
		
	}
}

void print_tree_recursive(node* root,deque<node*>& deq){
	if(root==NULL) return;
		deq.push_back(root);
	if(!root->left && !root->right){
		print_deq(deq);
		deq.pop_back();
	}
	if(root->left){
		print_tree_recursive(root->left,deq);
	}
	if(root->right){
		print_tree_recursive(root->right,deq);
	}
}
int main()
{
	node* root=init_tree();	
	deque<node*> mydeq;
	print_tree_recursive(root, mydeq);
	print_tree(root);
}
