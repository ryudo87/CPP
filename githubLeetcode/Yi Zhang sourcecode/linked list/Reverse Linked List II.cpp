#include "all.h"
//Reverse Linked List II
//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ≤ m ≤ n ≤ length of list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void reverse_list(ListNode* &head, ListNode* &tail)
{
	if(!head) return ;
	ListNode* cur=head, *next=head->next;
	while(cur && cur!=tail && next){
		ListNode* p=next->next;
		next->next=cur;
		cur=next;
		next=p;
	}

	ListNode* tmp=tail;
	tail=head;
	head=tmp;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode *cur=head,*tail=head, *lastTail=head;
	for(int i=0;i<m-2;++i){
		lastTail=lastTail->next;
	}
	if(m!=1)
		cur=lastTail->next;
	for(int i=0;i<n-1;++i){
		tail=tail->next;
	}
	ListNode* nextHead=tail->next;
	reverse_list(cur,tail);
	tail->next=nextHead;
	if(m!=1){
		lastTail->next=cur;
	}
	else
		head=cur;

	return head;
}
int main()
{
	map<string, int> mymap;

	int t=mymap["abc"];
	cout<<t<<endl;

	return 0;
}
