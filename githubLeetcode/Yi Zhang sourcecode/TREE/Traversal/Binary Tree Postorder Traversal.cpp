
//Binary Tree Postorder Traversal Total Accepted: 16036 Total Submissions: 52368 My Submissions
//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//1
//\
//2
///
//3
//return [3,2,1].


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> vec;
  if (!root) {
    return vec;
  }
  
  stack<TreeNode*> st;
  TreeNode *cur=root, *pre=NULL;
  while (cur || !st.empty()) {
    while (cur) {
      st.push(cur);
      cur=cur->left;
    }
    cur=st.top();
    
    if (cur->right==NULL || cur->right == pre) {
      st.pop();
      vec.push_back(cur->val);
      pre=cur;
      cur=NULL;
    } else {
      cur=cur->right;
    }
  }
  
  return vec;
}















struct node
{
	char name;
	int data;
	struct node* left;
	struct node* right;
	node(int i):left(0),right(0),data(i){}
};

int pre[]={1 ,2 ,4 ,7 ,3 ,6};
int in[]={ 4, 2,7, 1,3, 6};

void construct(int prefirst,int prelast,int infirst,int inlast,node* &root)
{
	if(prefirst>prelast||infirst>inlast)
    return;
	root=new node(pre[prefirst]);
  
	if(prefirst==prelast||infirst==inlast)
		return;
	int i=infirst;
	while(in[i]!=pre[prefirst])	++i;
	construct(prefirst+1,prefirst+i-infirst,infirst,i-1,root->left);
	construct(prefirst+i-infirst+1,prelast,i+1,inlast,root->right);
}



void postOrder(node* root)
{
	stack<node*> st;node* p=root;node* pre=NULL;
  
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			p=p->left;
		}
		p=st.top();
    
    
		if(p->right==NULL||p->right==pre){
			cout<<p->data<<endl;
			st.pop();
			pre=p;p=NULL;
		}
		else{
      
			p=p->right;
		}
    
	}
}
int main()
{
  
	node* root=NULL;
	construct(0,5,0,5,root);
	postOrder(root);
  
}