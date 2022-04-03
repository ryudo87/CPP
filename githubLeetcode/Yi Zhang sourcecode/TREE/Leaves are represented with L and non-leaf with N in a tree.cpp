
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include <strstream>
#include <new>
using namespace std;
//Leaves are represented with L and non-leaf with N in a tree. Each node has either 0 or 2 children.
//so if given preorder traversal of this tree, construct the tree.
struct node
{
	char name;
	int data;
	struct node* left;
	struct node* right;
	node(char ch,int i):name(ch),left(0),right(0),data(i){}
};

char input[]={'N','N','L','N','N','L','L','L','L'};
size_t len;
int construct(int index,node* &cur)
{
	if(index>len-1)
		return index+1;

	cur=new node(input[index],index);

	if(input[index]=='L')
		return index+1;
	else {
		int next=construct(index+1,cur->left);
		int n=construct(next,cur->right);
		return n;
	}

}
int main()
{
	len=sizeof(input)/sizeof(char);
	cout<<len<<endl;
	node* root;
	construct(0,root);
	cout<<root->name<<endl;
}
