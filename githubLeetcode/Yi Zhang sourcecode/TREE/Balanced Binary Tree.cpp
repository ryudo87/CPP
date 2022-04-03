Balanced Binary Tree Total Accepted: 13752 Total Submissions: 42932 My Submissions
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.





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
  bool isSubBalanced(TreeNode* root, int& depth) {
    if(!root) {
      depth=0;
      return true;
    }
    int depth_left=0;
    int depth_right=0;
    if(isSubBalanced(root->left, depth_left) && isSubBalanced(root->right, depth_right)) {
      if (abs(depth_left-depth_right) <= 1) {
        depth = max(depth_left, depth_right)+1;
        return true;
      }
    }
    return false;
    
  }
  bool isBalanced(TreeNode *root) {
    int depth=0;
    return isSubBalanced(root, depth);
  }
};