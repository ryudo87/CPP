Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3
Return 6.






http://yucoding.blogspot.com/2012/12/leetcode-question-13-binary-tree.html
Analysis:
This is a difficult problem, the value of the node could be "+"  or "-",  any node could be the start node or the end node.

A good idea found from the internet is:

1. Set one variable to store the max sum.
2. Scan every node in the tree.
3. For each node, compute the max sum of left sub tree and max sum of the right sub tree,
   the max sum is from the path that goes end at the left child, and start from any one of the node below the left child. (recursively)
4. Compare the max sum to the (left+right+current-val), be careful with the "-", if left<0 don't add left, same for the right. And update the max sum.


For each node(sub tree), there are two status, one is the path ends at this node, the other is the path goes through this node.
In the first case, the path sum is current-val+max(left_s,right_s). and the sum here can be used for the parent of this node.
In the second case, just compare the sum current-val+ left_s + right_s with the current max_sum, and update the max_sum.



// Submission Result: Accepted
class Solution {
  public:
  int max_s;
  
  int dfs(TreeNode *root){
    if (!root) {return 0;}
    int l = dfs(root->left);
    int r = dfs(root->right);
    int m = root->val;
    if (l>0) {m+=l;}
    if (r>0) {m+=r;}
    
    max_s = max(max_s,m);
    if (max(l,r)>0) { return max(l,r)+root->val; }
    else {return root->val;}
  }

  int maxPathSum(TreeNode *root) {
    max_s = -9999;
    dfs(root);
    return max_s;
  }
}






http://fisherlei.blogspot.com/2013/01/leetcode-binary-tree-maximum-path-sum.html
For each node like following, there should be four ways existing for max path:

1. Node only
2. L-sub + Node
3. R-sub + Node
4. L-sub + Node + R-sub

Keep trace the four path and pick up the max one in the end.


1:    int maxPathSum(TreeNode *root) {
  2:      // Start typing your C/C++ solution below
  3:      // DO NOT write int main() function
  4:      int maxAcrossRoot=INT_MIN;
  5:      int maxEndByRoot = GetMax(root, maxAcrossRoot);
  6:      return std::max(maxAcrossRoot, maxEndByRoot);
  7:    }
8:    int GetMax(TreeNode *node, int& maxAcrossRoot)
9:    {
  10:      if(node == NULL) return 0;
  11:      int left = GetMax(node->left, maxAcrossRoot);
  12:      int right = GetMax(node->right, maxAcrossRoot);
  13:      int cMax = node->val;
  14:      if(left>0)
  15:        cMax+=left;
  16:      if(rifht>0)
  17:        cMax+=right;
  18:      maxAcrossRoot = std::max(maxAcrossRoot, cMax);
  19:      return std::max(
                           20:        node->val,
                           21:        std::max(node->val+left, node->val+right));
  22:    }
