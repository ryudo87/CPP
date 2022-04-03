#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
	char content;
	Node* sibling;
	Node* firstChild;
	bool isWord;
public:
	Node(char c):content(c),sibling(NULL),firstChild(NULL),isWord(false){}
};
class Trie
{
	Node* root;
	void get_words(Node* curNode, string resArr[], int& index, const int maxNumOfResult, string& path);
public:
	void insert(const char* word);
	int search(const char* prefix, int maxNumOfResult, string* resArr );
	Trie(){
		root=new Node(0);
	}
};
void Trie::get_words(Node* curNode, string resArr[], int& index, const int maxNumOfResult, string& path)
{
	if(!curNode) return;
	if(index==maxNumOfResult){
		return ;
	}
	path.push_back(curNode->content);
	if(curNode->isWord){
		resArr[index++]=path;
	}
	get_words(curNode->firstChild, resArr, index, maxNumOfResult, path);
	path.erase(path.end()-1,path.end());
	get_words(curNode->sibling, resArr, index, maxNumOfResult,path);

}

int Trie::search(const char* prefix, int maxNumOfResult,string* resArr){
	if(!prefix) return -1;
	if(0==maxNumOfResult) return 0;
	const char* p=prefix;
	int index=0;
	Node* cur=root->firstChild;
	//walk through the prefix
	while(*p){
		while(cur && cur->content<*p){
			cur=cur->sibling;
		}
		if(!cur || cur->content>*p){//invalid prefix
			return 0;
		}
		if( !*(p+1) && cur->isWord)//the prefix itself is a word
			resArr[index++]=prefix;
		cur=cur->firstChild;
		p++;
	}

	//use recursion to get valid words in alphabetical order
	string path=prefix;
	get_words(cur,resArr,index,maxNumOfResult, path);

	return index;
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

