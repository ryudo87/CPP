Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:
1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.





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
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    
    return isMirror(root->left, root->right);
  }
  
  bool isMirror(TreeNode * leftSub, TreeNode *rightSub) {
    if (leftSub && rightSub) {
      if (leftSub->val != rightSub->val) {
        return false;
      }
      return isMirror(leftSub->left, rightSub->right) && isMirror(leftSub->right, rightSub->left);
    }
    
    if (!leftSub && !rightSub) {
      return true;
    }
    
    return false;
  }
};