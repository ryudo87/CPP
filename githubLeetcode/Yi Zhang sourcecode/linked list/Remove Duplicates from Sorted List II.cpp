Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.




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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode dummy(0);
    dummy.next=head;
    
    ListNode *prev=&dummy, *cur=head;
    while(cur){
      bool dup=false;
      while(cur->next && cur->val==cur->next->val){
        cur=cur->next;
        dup=true;
      }
      if(dup){
        prev->next=cur->next;
      }else{
        prev=prev->next;
      }
      cur=cur->next;
      
    }
    return dummy.next;
  }
};