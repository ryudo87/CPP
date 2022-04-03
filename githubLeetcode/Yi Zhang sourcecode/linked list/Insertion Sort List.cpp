
//这道题跟Sort List类似，要求在链表上实现一种排序算法，这道题是指定实现插入排序。插入排序是一种O(n^2)复杂度的算法，基本想法相信大家都比较了解，就是每次循环找到一个元素在当前排好的结果中相对应的位置，然后插进去，经过n次迭代之后就得到排好序的结果了。了解了思路之后就是链表的基本操作了，搜索并进行相应的插入。时间复杂度是排序算法的O(n^2)，空间复杂度是O(1)。代码如下：
ListNode *insertionSortList(ListNode *head) {
  if(!head||!head->next){
    return head;
  }
  ListNode helper(0);
  ListNode *pre=&helper, *cur=head;
  while(cur){
    ListNode *next=cur->next;
    pre=&helper;
    while(pre->next&&pre->next->val<cur->val) {
      pre=pre->next;
    }
    cur->next=pre->next;
    pre->next=cur;
    cur=next;
  }
  
  return helper.next;
}