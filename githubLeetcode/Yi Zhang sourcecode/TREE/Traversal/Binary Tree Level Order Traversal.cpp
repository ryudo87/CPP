#include "all.h"
//Binary Tree Level Order Traversal
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//

//return its level order traversal as:
//[
// [3],
// [9,20],
// [15,7]
//]

vector<vector<int> > res;
void DFS(TreeNode* p,int curlevel)
{
	if(!p) return;
	if(res.size()<curlevel+1){
		res.push_back(vector<int>());
	}
	res[curlevel].push_back(p->val);
	DFS(p->left,curlevel+1);
	DFS(p->right,curlevel+1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
  res.clear();
  if(!root) return res;
  DFS(root,0);
  return res;
}




//
//    binary tree level by level， print binary tree level by level; solve it without using a queue
//    这个是不是有几层就要做几次DFS?有没有更好的办法？
//    面我的人是想用in-place的方法， 不过需要node有parent指针， 用parent指针做back-track
//    back_track大概的logic是， 一直往上找parent, 直到回到root || 当前node==parent.left; 然后处理parent.right
//

// 1)   level-order traversal can be implemented using DFS too. See my next post: Binary Tree Level-Order Traversal Using Depth First Search (DFS) for the challenge.
//
// 2)   we can utilize two queues. The first queue stores the current level’s nodes, while the second queue stores the next level’s nodes (the current level nodes’ children).
//
//
// 3) The single queue solution requires two extra counting variables which keep tracks of the number of nodes
//in the current level (nodesInCurrentLevel) and the next level (nodesInNextLevel).
// When we pop a node off the queue, we decrement nodesInCurrentLevel by one.
// When we push its child nodes to the queue, we incrementnodesInNextLevel by two.
//
//
//










#include "all.h"

//binary tree level order print, append '\n' after each level
void print_tree_by_evel(TreeNode* myroot)
{
	queue<const TreeNode*> myQ;
	if(NULL==myroot) return;
	myQ.push(myroot);
	myQ.push(NULL);
	const TreeNode* cur;
	while(!myQ.empty()){
		cur=myQ.front();
		myQ.pop();
		if(NULL==cur){
			cout<<endl;
			if(myQ.empty()) break;
			myQ.push(NULL);
		}
		else{
			cout<<cur->val<<",";
			if(cur->left)
				myQ.push(cur->left);
			if(cur->right)
				myQ.push(cur->right);
		}
	}
}

//
//The challenge now is, can you do it using Depth First Search (DFS) this time?
//
//Hint:
//Write a function call printLevel(BinaryTree *p, int level) which will print all TreeNodes of a given level. Assume you know the height of the tree, then you can print the entire tree level by level utilizing printLevel.
//
//Solution:
//printLevel function can be solved using DFS. Decrement level by one as you advance to the next level. When level equals 1, you‚Äôve reached the given level. To find the maximum height (or the max depth) of a tree, you can read my post: Maximum Height of a Binary Tree.


int main()
{
	TreeNode* root=init_tree();
	print_tree_by_evel(root->right->left);
    
}

