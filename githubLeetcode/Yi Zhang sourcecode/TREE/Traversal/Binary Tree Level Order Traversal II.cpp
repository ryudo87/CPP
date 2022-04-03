#include "all.h"
//Binary Tree Level Order Traversal II
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},

// 	  3
//   / \
//  9  20
//    /  \
//   15   7

//return its bottom-up level order traversal as:
//[
//  [15,7]
//  [9,20],
//  [3],
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

vector<vector<int> > levelOrderBottom(TreeNode *root) {
  res.clear();
  if(!root) return res;
  DFS(root,0);
  //  !!!!
  reverse(res.begin(),res.end());
  return res;
}





//
//解题思路：
//
//居然要层次遍历，那么我们如果一层层放入到queue中，然后取出这一层结点，并把值放入到一个ArrayList<Integer>中，并加入到最终集合list中，接着我们把这一层的孩子结点，即下一层的结点再放入到queue中，这样直到queue为empty的时候，我们便把所有层次都遍历完毕了,这样子我们将 list 进行翻转，便得到了题目想要的结果了！！
