#include "all.h"

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Anwser 2 ：    BFS   in  queue
int maxDepth(TreeNode *root) {
  if (!root) {
    return 0;
  }
  
  queue<TreeNode*> myq;
  int h=1;
  myq.push(root);
  myq.push(NULL);
  
  while (!myq.empty()) {
    TreeNode* p = myq.front();
    myq.pop();
    
    if (!p) {
      if (myq.empty()) {
        return h;
      }
      myq.push(NULL);
      ++h;
    } else {
      if (p->left) {
        myq.push(p->left);
      }
      if (p->right) {
        myq.push(p->right);
      }
    }
    
  }
  
  return h;
}





Iterative Solution:
We could apply the same in-order traversal of a BST in the binary tree. By saying “in-order” traversal I mean traversing the tree such that it reaches the leaf first (deepest). In other words, we are doing a Depth-first Search (DFS). In fact, all three kinds of tree traversal (pre-order, in-order, and post-order) are doing DFS. Therefore, we could modify any existing iterative solution of tree traversals to solve this problem.

As pre-order and in-order iterative traversals are easier to implement, your best bet is to code either one of them during an interview session. As we traverse the tree, we would keep track of the current depth and record each node’s depth, so that we know which depth we are in when we return to the node at a later time. (In pre-order or in-order traversals, it might return several levels above the current level when a node is popped off the stack).

On the other hand, post-order traversal guarantees to return exactly one level above a node that is popped off the stack. Therefore, we could devise a solution utilizing post-order traversal without modifying the existing tree structure. We keep track of the current depth and update the maximum depth as we traverse the tree.

Another solution is to utilize Breadth-first Search (BFS). Unlike DFS, we traverse the tree level by level, thus we are able to obtain the max depth in a direct manner. Read my post: Printing a Binary Tree in Level Order for more information.