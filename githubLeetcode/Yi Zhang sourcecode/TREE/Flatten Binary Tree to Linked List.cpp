
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ????/
void flatten(TreeNode *root) {
  if (!root) {
    return;
  }
  
  stack<TreeNode*> right_st;
  
  TreeNode *cur=root;
  while (cur || !right_st.empty()) {
    while (cur->left) {
      if (cur->right) {
        right_st.push(cur->right);
      }
      cur->right = cur->left;
      cur=cur->left;
    }
    
    if (!cur->right && !right_st.empty()) {
      cur->right = right_st.top();
      right_st.pop();
    }
    cur=cur->right;
  }
  
}

int main() {
  TreeNode r1(1);
  TreeNode r2(2);
  r1.left=NULL;
  r1.right=&r2;
  flatten(&r1);
}



class Solution {
public:
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    
    stack<TreeNode*> right_st;
    right_st.push(root);
    TreeNode *cur, *prev=NULL;
    while (!right_st.empty()) {
      cur=right_st.top(); right_st.pop();
      
      if (cur->right) {
        right_st.push(cur->right);
      }
      if (cur->left) {
        right_st.push(cur->left);
      }
      if (prev) {
        prev->left=NULL;
        prev->right=cur;
      }
      prev=cur;
    }
  }
  
};
//这道题思路很清晰，就是递归，然后分别flat右和左，刚开始以为flat哪个先都无所谓，但实际是要先flatten右边的，不然flatten完左边，把左边的连上右边去，右边的已经不是bst了

class Solution {
public:
  TreeNode * build(TreeNode *root, TreeNode * right_root)
  {
    if(root){
      right_root = build(root->right, right_root);
      right_root = build(root->left, right_root);
      
      root->right=right_root;
      right_root=root;
      root->left=NULL;
    }
    
    return right_root;
  }
  void flatten(TreeNode *root) {
    
    TreeNode *tmp=NULL;
    build(root, tmp);
    
  }
};

