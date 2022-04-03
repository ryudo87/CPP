Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?




/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

http://yucoding.blogspot.com/2013/03/leetcode-question-75-recover-binary.html





用2个pointer，一个是pre，一个是current，若是current->val<pre->val, 那么纪录下cur, 遇到下一个再纪录下cur。以免遇到只有两个点儿的情况，要判断一下要不要纪录pre。

然后就是in-order traverse的变体。
还有一个分析得比较多的解法，可以看看 http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html

void proc(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev)
{
  if(!root)
    return;
  proc(root->left,n1,n2,prev);
  if(prev && prev->val > root->val)
  {
    n2 = root;
    if(!n1)
      n1 = prev;
  }
  prev = root;
  proc(root->right,n1,n2,prev);
}
void recoverTree(TreeNode *root) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  TreeNode *n1 = NULL;
  TreeNode *n2 = NULL;
  TreeNode *prev = NULL;
  proc(root,n1,n2,prev);
  if(n1 && n2)
    swap(n1->val,n2->val);
}





//Updates:  3/16/2013
//Searched in the web. Actually, there is a smart solution to travel the tree with two node.
//The link is http://discuss.leetcode.com/questions/272/recover-binary-search-tree






//   http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html


//
//O(1)的解法就是
//Inorder traverse, keep the previous tree node,
//Find first misplaced node by
//if ( current.val < prev.val )
//Node first = prev;
//
//Find second by
//if ( current.val < prev.val )
//Node second = current;
//
//After traversal, swap the values of first and second node. Only need two pointers, prev and current node. O(1) space.
//
//但是这个解法的前提是Traverse Tree without Stack. 中序遍历如何才能不使用栈。这里就要引入一个概念， Threaded Binary Tree。So, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.



//1. Initialize current as root
//2. While current is not NULL
//If current does not have left child
//  a) Print current’s data
//  b) Go to the right, i.e., current = current->right
//Else
//  a) Make current as right child of the rightmost node in current's left subtree
//  b) Go to this left child, i.e., current = current->left



//代码如下：

/* Function to traverse binary tree without recursion and without stack */
vector<int> inorderTraversal(TreeNode *root)
{
  vector<int> result;
  TreeNode  *current,*pre;
  
  if(root == NULL)
    return result;
  
  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      result.push_back(current->val);
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;
      
      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }
      
      /* Revert the changes made in if part to restore the original
       tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        result.push_back(current->val);
        current = current->right;
      } /* End of if condition pre->right == NULL */
    } /* End of if condition current->left == NULL*/
  } /* End of while */
  
  return result;
}

//
//那么，基于这个双指针遍历，可以把错置节点的判断逻辑加进去，就可以完美的在O(1)空间内，完成树的重构。
//
//[Code]
//改动代码如红字所示。增加了一个pointer -- parent来记录上一个访问节点。整个遍历过程中，使用（parent->val > current->val）来寻找违规节点，但是区别是，要获取第一次violation的parent和第二次violation的current，然后交换。






void recoverTree(TreeNode *root)
{
  TreeNode *f1=NULL, *f2=NULL;
  TreeNode  *current,*pre, *parent=NULL;
  
  if(root == NULL)
    return;
  bool found = false;
  current = root;
  
  while (current) {
    if (current->left == NULL) {
      if (parent && parent->val > current->val) {
        if (!found) {
          f1 = parent;
          found = true;
        }
        f2 = current;
      }
      
      parent = current;
      current = current->right;
      
    } else {
      pre = current->left;
      while (pre->right && pre->right != current) {
        pre = pre->right;
      }
      
      
      
      if (pre->right == NULL) {/* Make current as right child of its inorder predecessor */
        pre->right = current;
        current = current->left;
      } else {
        /* Revert the changes made in if part to restore the original
         tree i.e., fix the right child of predecssor */
        pre->right = NULL;
        if (parent && parent->val > current->val) {
          if (!found) {
            f1 = parent;
            found = true;
          }
          f2 = current;
        }
        
        parent = current;
        current = current->right;
      }
      
    }
  }
  
  
  
  if (f1 && f2) {
    swap(f1->val, f2->val);
  }
  
}

