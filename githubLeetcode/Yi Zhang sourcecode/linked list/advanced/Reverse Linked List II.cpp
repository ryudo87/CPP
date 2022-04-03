//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,

//return 1->4->3->2->5->NULL.

//Note:
//Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.




// http://fisherlei.blogspot.com/2012/12/leetcode-reverse-linked-list-ii.html


ListNode *reverseBetween(ListNode *head, int m, int n) {

  ListNode dummy(0);
  dummy.next = head;
  
  ListNode *preM, *pre = &dummy;
  for (int i = 1; i <= n; ++i) {
    if (i == m) preM = pre;
    
    if (i > m && i <= n) {
      pre->next = head->next;
      head->next = preM->next;
      preM->next = head;
      head = pre; // head has been moved, so pre becomes current
    }
    
    pre = head;
    head = head->next;
  }
  
  return dummy.next;
}