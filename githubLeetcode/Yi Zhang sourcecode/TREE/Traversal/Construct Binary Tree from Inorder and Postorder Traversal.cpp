Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.




// Accepted


class Solution {
  map<int,int> val2index;
  void initMap(const vector<int> &inorder) {
    for (int i=0;i<inorder.size(); ++i) {
      val2index[ inorder[i] ] = i;
    }
  }
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend){
    if (postend - poststart <1 || inend - instart < 1)
      return NULL;
    int val = postorder[postend-1];
    int split = val2index[val];
    
    TreeNode *root = new TreeNode(val);
    
    root->left = build(inorder, postorder, instart, split, poststart, poststart + split - instart);
    root->right = build(inorder, postorder, split+1, inend, poststart+split-instart, postend-1);
    return root;
  }
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    initMap(inorder);
    int len = inorder.size();
    TreeNode *root = build(inorder, postorder, 0, len, 0, len);
    return root;
  }
};

