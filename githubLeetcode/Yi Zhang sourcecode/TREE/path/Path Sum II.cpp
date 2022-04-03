Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
 [5,4,11,2],
 [5,8,4,5]
]



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  
  void getPath(TreeNode *root, vector<int> path, int sum, vector<vector<int> >& ma) {
    if (!root) {
      return;
    }
    
    path.push_back(root->val);
    if (!root->left && !root->right) {
      if (sum == root->val) {
        ma.push_back(path);
      }
      return;
    }
    
    getPath(root->left, path, sum-root->val, ma);
    getPath(root->right, path, sum-root->val, ma);
    path.pop_back();
    
  }
  
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ma;
    vector<int> path;
    
    getPath(root, path, sum, ma);
    
    
    return ma;
  }
};