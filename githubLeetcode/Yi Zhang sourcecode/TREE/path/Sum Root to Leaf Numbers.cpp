
Sum Root to Leaf Numbers Total Accepted: 13585 Total Submissions: 46472 My Submissions
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.


1. 如何分情况？
2. 如何递归到该点的时候该如何操作？
3. 由跟节点到叶子节点的时候，每进入一层就需要把前面的值*10，如何处理这个值？总值又是如何保存的呢？
问题处理：
1 分情况就是：一 空节点， 二 到了叶子节点 三 一般节点（包括只有左孩子，只有右孩子，两个孩子都有）
2 递归到该点的时候就把这点的值与前面的值乘以10，然后相加
3 需要如何保存前面的值？以参数传递的方式保存，以供下一层使用。总值可以以两种方式保存：参数传递方式，返回函数值方式。

/////////
class Solution {
public:
  //2014-2-18 update
	int sumNumbers(TreeNode *root)
	{
		return sumup(root);
	}
	int sumup(TreeNode *r, int path = 0)
	{
		if (!r) return 0;
		if (!r->left && ! r->right) return 10*path+r->val;
		return sumup(r->left, 10*path+r->val)+sumup(r->right, 10*path+r->val);
	}
  
};

///////////////// my method

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    int sum = getSum(root, 0);
    if (sum == -1) {
      return 0;
    }
  }
  int getSum(TreeNode *root, int prefix_val) {
    
    if (!root) {
      return -1;
    }
    int left_sum = getSum(root->left, 10*prefix_val+root->val);
    int right_sum = getSum(root->right, 10*prefix_val+root->val);
    
    
    if (left_sum == -1 && right_sum == -1) {
      return 10*prefix_val+root->val;
    }
    
    if (left_sum == -1) {
      return right_sum;
    }
    
    if (right_sum == -1) {
      return left_sum;
    }
    
    return left_sum+right_sum;
  }
  
};