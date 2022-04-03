#include "all.h"



/**
 * Definition for singly-linked list with a random pointer.
 */

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// Submission Result: Accepted

class Solution {
  void copyAndInsertNewList(RandomListNode *old_head) {
    RandomListNode *old_cur = old_head, *new_cur = NULL;
    
    while (old_cur) {
      new_cur = new RandomListNode(old_cur->label);
      new_cur->next = old_cur->next;
      old_cur->next = new_cur;
      old_cur = new_cur->next;
    }
  }
  
  void setNewListRandomPointer(RandomListNode *old_head) {
    RandomListNode *old_cur = old_head, *new_cur = old_head->next;
    
    while (old_cur) {
      // check if random is NULL
      new_cur->random = old_cur->random ? old_cur->random->next : NULL;
      old_cur = new_cur->next;
      
      if (!old_cur) {
        return;
      }
      new_cur = old_cur->next;
    }
  }
  
  RandomListNode* restoreAllList(RandomListNode *old_head) {
    RandomListNode *cur = old_head, *new_head = old_head->next;
    
    while (cur->next) {
      RandomListNode *tmp = cur->next;
      cur->next = cur->next->next;
      cur = tmp;
    }
    
    return new_head;
  }
  
public:
  RandomListNode* copyRandomList(RandomListNode *head) {
    RandomListNode * newHead = NULL;
    if (!head) {
      return NULL;
    }
    
    copyAndInsertNewList(head);
    
    setNewListRandomPointer(head);
    
    newHead = restoreAllList(head);
    
    return newHead;
  }
};