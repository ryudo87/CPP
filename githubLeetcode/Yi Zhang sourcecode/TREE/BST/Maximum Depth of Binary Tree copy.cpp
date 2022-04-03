Minimum Depth of Binary Tree Total Accepted: 12911 Total Submissions: 44571 My Submissions
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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