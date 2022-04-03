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
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }
    ListNode *p_fast(head->next), *p_slow(head);
    
    while(p_fast && p_slow) {
      if (p_fast == p_slow) {
        return true;
      }
      if (!p_fast->next) {
        return false;
      }
      p_fast=p_fast->next->next;
      p_slow=p_slow->next;
      
    }
    
    return false;
  }
};