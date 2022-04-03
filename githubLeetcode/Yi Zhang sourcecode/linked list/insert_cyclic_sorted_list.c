#include <list.h>

int main()
{
	node* cur=init_list();
	scanf("%d",&t);
	node* new_node=(node*)malloc(sieof(node));
	while(1){
		if(cur->val<=t && cur->next->val>=t){
			new_node->next=cur->next;cur->next=new_node;break;
		}
		else if( cur->next->val<cur->val){
			new_node->next=cur->next;cur->next=new_node;break;
			
		}
		cur=cur->next;
	}

return 0;
}
