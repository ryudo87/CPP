#include <cstdio>
#include <iostream>
#include <cassert>
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
	void get_words(Node* curNode, char** resArr, int& index, const int maxNumOfResult, char* path, int pathLen);
	char** init_strArr(int size);
public:
	void insert(const char* word);
	char** search(const char* prefix, int maxNumOfResult );
	Trie(){
		root=new Node(0);
	}
};




void Trie::get_words(Node* curNode, char** resArr, int& index, const int maxNumOfResult, char* path, int pathLen)
{
	if(!curNode) return;
	if(index==maxNumOfResult){
		return ;
	}
	assert(pathLen<MAX_WORD_LEN);
	path[pathLen++]=curNode->content;

	if(curNode->isWord){
		strcpy(resArr[index++],path);
	}
	get_words(curNode->firstChild, resArr, index, maxNumOfResult, path, pathLen);
	path[--pathLen]=0;
	get_words(curNode->sibling, resArr, index, maxNumOfResult,path, pathLen);

}
char** Trie::init_strArr(int size)
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
	char** resArr=init_strArr(maxNumOfResult);
	char* path=new char[MAX_WORD_LEN];
	strcpy(path,prefix);

	//walk through the prefix
	Node* cur=root->firstChild;
	while(*p){
		while(cur && cur->content<*p){
			cur=cur->sibling;
		}
		if(!cur || cur->content>*p){//invalid prefix
			return 0;
		}
		if( !*(p+1) && cur->isWord)//the prefix itself is a word
			strcpy(resArr[index++],prefix);
		cur=cur->firstChild;
		p++;
	}

	//use recursion to get valid words in alphabetical order
	get_words(cur,resArr,index,maxNumOfResult, path,strlen(path));

	return resArr;
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
