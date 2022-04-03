#include "all.h"

//Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

//test case:
//empty list
//one node
//odd
//even
//loop

ListNode *swapPairs(ListNode *head) {
	if(!head) return NULL;
	ListNode *newhead=head, * cur=head, *next=head->next, *prev=NULL;

	while(next){
		cur->next=next->next;
		next->next=cur;
		if(prev){
			prev->next=next;
		}
		prev=cur;
		cur=cur->next;
		if(newhead==head)
			newhead=next;
		if(!cur) break;
		next=cur->next;
	}
	return newhead;
}




