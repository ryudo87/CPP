Minimum Depth of Binary Tree Total Accepted: 12911 Total Submissions: 44571 My Submissions
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.









//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

bool isValidBST(TreeNode *root) {
  if (!root) {
    return true;
  }
  
  return isValidSub(root->left, INT_MIN, root->val) && isValidSub(root->right, root->val, INT_MAX);
  
}

bool isValidSub(TreeNode *root, int min_val, int max_val) {
  if (!root) {
    return true;
  }
  
  if (root->val >= max_val || root->val <= min_val) {
    return false;
  }
  
  return isValidSub(root->left, min_val, root->val) && isValidSub(root->right, root->val, max_val);
}



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
  int minDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
    return 0;
    
    if (root->left == NULL && root->right == NULL)
    return 1;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    if (leftDepth == 0)
    return rightDepth + 1;
    else if (rightDepth == 0)
    return leftDepth + 1;
    else
    return min(leftDepth, rightDepth) + 1;
  }
};



1:    int minDepth(TreeNode *root) {
  2:      // Start typing your C/C++ solution below
  3:      // DO NOT write int main() function
  4:      if(root == NULL)
  5:        return 0;
  6:      int lmin = minDepth(root->left);
  7:      int rmin = minDepth(root->right);
  8:      if(lmin ==0 && rmin ==0)
  9:        return 1;
  10:      if(lmin ==0)
  11:      {
    12:        lmin = INT_MAX;
    13:      }
  14:      if(rmin ==0)
  15:      {
    16:        rmin = INT_MAX;
    17:      }
  18:      return min(lmin, rmin) +1;
  19:    }