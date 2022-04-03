


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(N)
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int> &num, int start, int end) {
    if (start > end) {
      return NULL;
    }
    // same as (start+end)/2, avoids overflow.
    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(num[mid]);
    node->left = sortedArrayToBST(num, start, mid-1);
    node->right = sortedArrayToBST(num, mid+1, end);
    return node;
  }
  
  TreeNode *sortedArrayToBST(vector<int> &num) {
    return sortedArrayToBST(num, 0, num.size()-1);
  }
};