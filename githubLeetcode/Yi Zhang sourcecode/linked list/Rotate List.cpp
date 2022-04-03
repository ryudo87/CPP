Rotate List Total Accepted: 8958 Total Submissions: 41426 My Submissions
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if(!head||!head->next) {
      return head;
    }
    int len=0;
    ListNode *cur=head;
    while(cur){
      cur=cur->next;
      ++len;
    }
    
    k=k%len;
    if(k==0){
      return head;
    }
    ListNode *tail=head,*new_tail=head;
    for(int i=0;i<k;++i){
      tail=tail->next;
    }
    while(tail->next){
      tail=tail->next;new_tail=new_tail->next;
    }
    tail->next=head;
    head=new_tail->next;
    new_tail->next=NULL;
    return head;
    
  }
};



