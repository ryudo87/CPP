#include "all.h"


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  map<int,int> val2index;
  void initMap(const vector<int> &inorder) {
    for (int i=0;i<inorder.size(); ++i) {
      val2index[ inorder[i] ] = i;
    }
  }
  
  TreeNode *build(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int prestart, int preend){
    if (preend - prestart <1 || inend - instart < 1) {
      return NULL;
    }
    
    int val = preorder[prestart];
    int split = val2index[val];
    
    TreeNode *root = new TreeNode(val);
    root->left = build(inorder, preorder, instart, split, prestart+1, 1+prestart + split - instart);
    root->right = build(inorder, preorder, split+1, inend, prestart+split-instart+1, preend);
    
    return root;
  }
  
  
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int len = inorder.size();
    initMap(inorder);
    TreeNode *root = build(inorder, preorder, 0, len, 0, len);
    return root;
  }
};

/////////////////////////////////////////////////////////////////////////


struct node
{
	char name;
	int data;
	struct node* left;
	struct node* right;
	node(int i):left(0),right(0),data(i){}
};

int pre[]={1 ,2 ,4  ,3 ,6};
int in[]={ 4, 2, 1,6, 3};
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
int main()
{
	node* root=NULL;
	construct(0,4,0,4,root);
	cout<<root->data<<endl;
}

