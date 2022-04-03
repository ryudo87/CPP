Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.





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
    if(!head||!head->next){
      return head;
    }
    ListNode *prev=head, *cur=head;
    while(prev){
      while(cur && prev->val==cur->val){
        cur=cur->next;
      }
      prev->next=cur;
      prev=cur;
    }
    return head;
  }
};