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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast(head), *slow(head);
    while(fast&&slow){
      if(!fast->next){
        return NULL;
      }
      fast=fast->next->next;
      slow=slow->next;
      if(fast==slow){
        break;
      }
    }
    if(fast==NULL) {
      return NULL;
    }
    slow=head;
    while(slow!=fast){
      fast=fast->next;
      slow=slow->next;
    }
    return fast;
  }
  
};