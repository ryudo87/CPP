#include "all.h"
//Implement find() in a skip list + some more(phone screens)	Feb. 10, 2009 11:47pm
//
//skip list is a randomized data structure built from a sorted linked list which allows average search time to be O(log(N)) 
//
//We chat about the minute or two about the pointers/graph/etc - candidate asks questions if any. 
//
//I ask them to write a data structure which can represent the skip list. There are couple of options but most people go with 
//#define MAX_LEVELS 10 
//struct SkipListNode {
//    int value; 
//    struct SkipListNode* next[MAX_LEVELS];
//} 
//SkipListNode* head;
//Some of them choose to dynamically allocate SkipListNodes - and that is fine - but then they have to be more careful about their pointers.
//Some make set of linked lists and head is array of those pointers. 
//I point out that they are duplicating data in every linked list (since the data is int). If they insist on the approach, I say "ok" - but they soon discover they must add one more SkipListNode* to point to the level below for this implementation. At that point, they revert to the top design.
//
//Then I ask them to implement 
//SkipListNode* find(int value);
//
//If they finish that quickly, or if you think that is too simple, ask them to find the first and the last element in the range given range. 
//void find(int lower_bound, int upper_bound, SkipListNode** first, SkipListNode** last);
//
//I think that the find() is pretty simple but not trivial: it is similar to linked lists (should be easy to grasp quickly), tests pointer arithmetics, checks clarity of the way people think about data structures. Decent candidate should be able to do it relatively quickly. 
//The second part is actually not much harder, but cannot rely on find()- as the boundaries of the region may not be in the list (say I am looking for range (-5, 30) and the list has -10, -4, 3, 22, 45). 
//
//Common places for errors... 
//For some reason, many candidates backtrack in search - rather than just checking the value of the next element. They also tend to forget to use index of the pointer in their code.. (I just ask them "which of the pointers are you at now?) 
//                                                                                                                                                                                      
//                                                                                                                                                                                      If they are stuck, we go back to the graph and look at specific example: say find 5.




#define MAX_LEVEL 3
struct SkipListNode{
	int value;
	SkipListNode* next[MAX_LEVEL];
	SkipListNode(int i=0):value(i){memset(next,0,sizeof(SkipListNode*)*MAX_LEVEL);}
};
//level 0)  //1     ->			 9
//level 1)	//1   ->   5	 ->  9
//level 2)  //1 -> 3 ->5 ->  7-> 9 -> 11


SkipListNode* init_skipList()
{
	SkipListNode* head=new SkipListNode(0),*cur=NULL;
	vector<SkipListNode*> vec;
	for(int k=1;k<=12;k+=2){
		SkipListNode* p=new SkipListNode(k);
		vec.push_back(p);
	}

	for(int i=0;i<vec.size()-1;++i){
		vec[i]->next[2]=vec[i+1];
	}

	vec[0]->next[1]=vec[2];
	vec[0]->next[0]=vec[4];
	vec[2]->next[1]=vec[4];
	vec[4]->next[0]=vec[5];

	head->next[0]=vec[0];
	head->next[1]=vec[0];
	head->next[2]=vec[0];
	head->value=0;
	return head;
}

//level 2)  //1     ->			 9
//level 1)	//1   ->   5	 ->  9
//level 0)  //1 -> 3 ->5 ->  7-> 9 -> 11
SkipListNode* find(SkipListNode* head,int target)
{
	SkipListNode* cur=head->next[0];int level=0;
	while(cur && level < MAX_LEVEL)
	{
		if(cur->value==target) return cur;
		if(cur->value<target){
			if(cur->next[level]==NULL || cur->next[level]->value > target){
				level++;
			}
			else cur=cur->next[level];
		}
		else return NULL;
	}
	return NULL;
}
TEST(find, manual)
{
	SkipListNode* head=init_skipList();
	SkipListNode* p=find(head,1);
	ASSERT_EQ(p->value,1);
	 p=find(head,3);
	ASSERT_EQ(p->value,3);
	 p=find(head,9);
	ASSERT_EQ(p->value,9);
	 p=find(head,11);
	ASSERT_EQ(p->value,11);

	 p=find(head,12);
	 ASSERT_TRUE(p==NULL);;
	 p=find(head,6);
	 ASSERT_TRUE(p==NULL);
	 p=find(head,0);
	 ASSERT_TRUE(p==NULL);
}

//level 2)  //1     ->			 9
//level 1)	//1   ->   5	 ->  9
//level 0)  //1 -> 3 ->5 ->  7-> 9 -> 11

//find first &last element in the range
void findRange(SkipListNode* head,int lbd,int ubd,SkipListNode** first, SkipListNode** last)
{
	*first=NULL;*last=NULL;
	if(!head || lbd>ubd){
		return;
	}
	SkipListNode* cur=head;
	int level=0;
	while(cur && (!*first || !*last)){
		if(!*first && cur->next[level] && lbd==cur->next[level]->value){
			*first=cur->next[level];
		}
		if(!*last && cur->next[level] && ubd==cur->next[level]->value){
			*last=cur->next[level];
		}
		if(!*first && cur->next[level] &&   cur->next[level]->value < lbd){
			cur=cur->next[level];
			continue;
		}

		if(!*first && cur->next[level] &&  lbd < cur->next[level]->value && (cur==head || lbd > cur->value)){
			if(MAX_LEVEL == level+1) {
				*first=cur->next[level];
			}
			else{level++;continue;}
		}

		if(!*last && cur->next[level] && cur->next[level]->value < ubd){
			cur=cur->next[level];
			continue;
		}

		if(!*last && cur!=head && cur->value < ubd){
			if(MAX_LEVEL == level+1) {
				*last=cur;
			}
			else{level++;continue;}
		}

		cur=cur->next[level];
	}

	if(!*last) *first=NULL;
	if(!*first) *last=NULL;
}
TEST(findRange, manual)
{
	SkipListNode* head=init_skipList();
	SkipListNode *first=NULL, *last=NULL;
	findRange(head,3,5,&first, &last);
	ASSERT_TRUE(3==first->value && 5==last->value);

	findRange(head,0,5,&first, &last);
	ASSERT_TRUE(1==first->value && 5==last->value);
	findRange(head,3,12,&first, &last);
	ASSERT_TRUE(3==first->value && 11==last->value);
	findRange(head,-1,13,&first, &last);
	ASSERT_TRUE(1==first->value && 11==last->value);
	findRange(head,3,3,&first, &last);
	ASSERT_TRUE(3==first->value && 3==last->value);
	findRange(head,11,13,&first, &last);
	ASSERT_TRUE(11==first->value  && 11==last->value);
	findRange(head,11,13,&first, &last);
	ASSERT_TRUE(11==first->value  && 11==last->value);

	findRange(head,13,113,&first, &last);
	ASSERT_TRUE(NULL==first && NULL==last);
	findRange(head,-1,0,&first, &last);
	ASSERT_TRUE(NULL==first && NULL==last);
	findRange(head,3,-3,&first, &last);
	ASSERT_TRUE(NULL==first && NULL==last);
}

