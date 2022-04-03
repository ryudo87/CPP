Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?




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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> vec;
    if (!root) {
      return vec;
    }
    
    stack<TreeNode*> st;
    TreeNode *cur=root;
    while (cur || !st.empty()) {
      while (cur) {
        vec.push_back(cur->val);
        st.push(cur);
        cur=cur->left;
      }
      cur=st.top();
      st.pop();
      
      cur=cur->right;
      
    }
    
    return vec;    
    
  }
};