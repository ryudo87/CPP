Naive Solution:
A naive way is to apply the previous solution directly. In each recursive call, you would have to traverse half of the list’s length to find the middle element. The run time complexity is clearly O(N lg N), where N is the total number of elements in the list. This is because each level of recursive call requires a total of N/2 traversal steps in the list, and there are a total of lg N number of levels (ie, the height of the balanced tree).

Hint:
How about inserting nodes following the list’s order? If we can achieve this, we no longer need to find the middle element, as we are able to traverse the list while inserting nodes to the tree.


Best Solution:

we no longer create nodes in the tree using the top-down approach. We create nodes bottom-up, and assign them to its parents. The bottom-up approach enables us to access the list in its order while creating nodes.


the algorithm requires the list’s length to be passed in as the function’s parameters. The list’s length could be found in O(N) time by traversing the entire list’s once. The recursive calls traverse the list and create tree’s nodes by the list’s order, which also takes O(N) time. Therefore, the overall run time complexity is still O(N).


// O(N)
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* &head, int start, int end) {
    if (start > end) {
      return NULL;
    }
    // same as (start+end)/2, avoids overflow.
    int mid = start + (end - start) / 2;
    TreeNode* left_child = sortedListToBST(head, start, mid-1);
    TreeNode* parent = new TreeNode(head->val);
    parent->left=left_child;
    head=head->next;
    parent->right=sortedListToBST(head, mid+1, end);
    return parent;
  }
  
  TreeNode *sortedListToBST(ListNode *head) {
    int sz=0;
    ListNode* cur=head;
    while (cur) {
      ++sz;cur=cur->next;
    }
    return sortedListToBST(head, 0, sz-1);
  }
};