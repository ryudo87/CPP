#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_WORD_LEN 256
struct Node
{
	char content;
	Node* sibling;
	Node* firstChild;
	bool isWord;
	Node(char c):content(c),sibling(NULL),firstChild(NULL),isWord(false){}
};
class Trie
{
	Node* root;
	void get_words(Node* curNode, char** res, int& index, const int maxNumOfResult, char* path, int pathLen);
public:
	void insert(const char* word);
	char** search(const char* prefix, int maxNumOfResult );
	Trie(){
		root=new Node(0);
	}
};
void Trie::get_words(Node* curNode, char** res, int& index, const int maxNumOfResult, char* path, int pathLen)
{
	if(!curNode) return;
	if(index==maxNumOfResult){
		return ;
	}
	path[pathLen++]=curNode->content;
	cout<<"path:"<<path<<endl;
	if(curNode->isWord){
		strcpy(res[index++],path);
	}
	get_words(curNode->firstChild, res, index, maxNumOfResult, path, pathLen);
	path[--pathLen]=0;
	cout<<path<<endl;
	get_words(curNode->sibling, res, index, maxNumOfResult,path, pathLen);

}
char** init_strArr(int size)
{
	char** arr=new char*[size];
	for(int i=0;i<size;++i){
		arr[i]=new char[MAX_WORD_LEN];
		memset(arr[i],0,MAX_WORD_LEN);
	}
	return arr;
}

char** Trie::search(const char* prefix, int maxNumOfResult){
	if(!prefix) return NULL;
	if(0==maxNumOfResult) return 0;
	const char* p=prefix;
	int index=0;
	char** res=init_strArr(maxNumOfResult);
	char* path=new char[MAX_WORD_LEN];
	strcpy(path,prefix);

	//walk down to the node of last character of prefix
	Node* cur=root->firstChild;
	while(*p){
		while(cur && cur->content<*p){
			cur=cur->sibling;
		}
		if(!cur || cur->content>*p){//invalid prefix
			return 0;
		}
		if( !*(p+1) && cur->isWord)//the prefix itself is a word
			strcpy(res[index++],prefix);
		cur=cur->firstChild;
		p++;
	}

	//use recursion to get valid words in alphabetical order
	get_words(cur,res,index,maxNumOfResult, path,strlen(path));

	return res;
}
void Trie::insert(const char* word){
	if(!*word) return;
	const char* p=word;
	Node *parent=root, *cur=root->firstChild;

	while(*p){
		if(!cur|| cur->content > *p){//target Node does not exist and it should be the first child of the parent
			Node* tmp=new Node(*p);
			tmp->sibling=cur;
			parent->firstChild=tmp;
			parent=tmp;
		}
		else{
			if(cur->content == *p){//target Node is the first child
				parent=cur;
			}
			else{
				Node* next=cur->sibling;
				while(next && next->content<*p ){//look for target Node following sibling links
					cur=next;
					next=cur->sibling;
				}
				if( !next || next->content!=*p){//target Node does not exist
					Node* tmp=new Node(*p);
					tmp->sibling=next;
					cur->sibling=tmp;
				}
				parent=cur->sibling;
			}
		}
		cur=parent->firstChild;
		++p;
	}
	parent->isWord=true;

}
int main()
{
	Trie trie;
	trie.insert("act");
	trie.insert("bar");
	trie.insert("ace");
	trie.insert("ads");
	trie.insert("ac");
	int maxNumOfResult;
	cin>>maxNumOfResult;
	char* prefix=new char[MAX_WORD_LEN];
	cin>>prefix;
	char** res=trie.search(prefix,maxNumOfResult);
	cout<<"final:"<<endl;
	for(int i=0;i<maxNumOfResult;++i){
		cout<<res[i]<<endl;
	}
	cout<<"!!done"<<endl;
}
