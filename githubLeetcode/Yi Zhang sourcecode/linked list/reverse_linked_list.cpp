template<class T>
struct Node
{
	T val;
	Node* next;
};

/*reverse a single linked list using non-recursive way*/
template<class T>
Node<T>* reverse_list_nonrecursion(Node<T>* head)
{
	if(!head) return NULL;

	Node<T>* curNodeP=head;
	curNodeP=head;
	Node<T>* nextNodeP=curNodeP->next, *prevNodeP=NULL;
	while(curNodeP){
		curNodeP->next=prevNodeP;
		prevNodeP=curNodeP;
		curNodeP=nextNodeP;
		if(nextNodeP)
			nextNodeP=nextNodeP->next;
	}
	curNodeP=prevNodeP;
	return curNodeP;
}

/*reverse a single linked list using recursion*/
template<class T>
Node<T>* reverse_list_recursion(Node<T>* head)
{
	if(!head) return NULL;
	Node<T>* newHead=head;//newHead is the head Node of reversed linked list

	if(NULL!=head->next){
		Node<T>* nextNodeP=head->next;
		newHead=reverse_list_recursion(head->next);
		nextNodeP->next=head;
		head->next=NULL;
	}
	return newHead;
}
