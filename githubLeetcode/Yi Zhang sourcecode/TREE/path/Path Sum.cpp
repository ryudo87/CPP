//打印和为一个定值的路径
Path Sum Total Accepted: 14167 Total Submissions: 47174 My Submissions
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root==NULL) {return false;}
    if ( (root->left==NULL) && (root->right==NULL) && (sum-root->val==0) ) {return true;}
    return (hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val));
  }
};

using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int i,Node* l=NULL,Node* r=NULL):val(i),left(l),right(r){}
};
void print(deque<int> path,int start,int end)
{
	for(int i=start;i<=end;++i)
		cout<<path[i]<<",";
	cout<<endl;
}
void findSum(Node *node, int sum, deque<int> path,int level)
{
	if(node==NULL) return;
	path.push_back(node->val);
	//path[level]=node->val;
	int t=0;
	for(int i=level;i>=0;i--){
		t+=path[i];
		if(t==sum) print(path,i,level);
	}
  
	findSum(node->left,sum,path,level+1);
	findSum(node->right,sum,path,level+1);
  
	path.pop_back();
}
int main(int argc, _TCHAR* argv[])
{
	
	Node n6(6);
	Node n5(-2,NULL,&n6);
	Node n4(2);
	Node n3(-4,NULL,&n5);
	Node n2(1,&n4);
	Node n1(3,&n3);
	Node n0(2,&n1,&n2);
	deque<int> path;
	findSum(&n0, 5, path,0);
	return 0;
}

