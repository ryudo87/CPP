Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.




[解题思路]
从左往右扫描，找到第一个大于X的指针，然后再该指针左边，不断插入小于X的元素。这里为了避免处理head是否为空的检测，在头指针位置先插入一个干扰元素，以保证head永不为空，然后在最后返回的时候删除掉。
// Submission Result: Accepted
ListNode *partition(ListNode *head, int x) {
  if(!head || !head->next){
    return head;
  }
  ListNode dummy(x-1);
  dummy.next=head;
  ListNode *tmp=NULL, *prev=&dummy, *cur=head;
  
  while(cur){
    if(cur->val>=x){
      tmp=prev;
      break;
    }
    prev=prev->next;
    cur=cur->next;
  }
  
  if(!cur){
    return head;
  }
  
  prev=cur;
  cur=cur->next;
  
  while(cur){
    if(cur->val<x){
      prev->next=cur->next;
      cur->next=tmp->next;
      tmp->next=cur;
      cur=prev->next;
      tmp=tmp->next;
    }else{
      prev=prev->next;
      cur=cur->next;
    }
  }
  
  return dummy.next;
}

