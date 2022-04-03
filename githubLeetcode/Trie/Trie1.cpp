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
	Node(char c):content(c),sibling(NULL),firstChild(NULL),isWord(false){}
};
class Trie
{
	Node* root;
public:
	void insert(const char* word);
	int search(const char* prefix, int maxNumOfResult, string* res );
	Trie(){
		root=new Node(0);
	}
};
void get_words(Node* curNode, string res[], int& index, const int maxNumOfResult, string& path)
{
	if(!curNode) return;
	if(index==maxNumOfResult){
		return ;
	}
	path.push_back(curNode->content);
	cout<<path<<endl;
	if(curNode->isWord){
		res[index++]=path;
	}
	get_words(curNode->firstChild, res, index, maxNumOfResult, path);
	path.erase(path.end()-1,path.end());
	cout<<path<<endl;
	get_words(curNode->sibling, res, index, maxNumOfResult,path);

}
void init_strArr(string* strArr,int len, const string& prefix)
{
	for(int i=0;i<len;++i){
		strArr[i]=prefix;
	}
}
int Trie::search(const char* prefix, int maxNumOfResult,string* res){
	if(!prefix) return -1;
	if(0==maxNumOfResult) return 0;
	const char* p=prefix;
	int index=0;
	Node* cur=root->firstChild;
	//walk down to the node of last character of prefix
	while(*p){
		while(cur && cur->content<*p){
			cur=cur->sibling;
		}
		if(!cur || cur->content > *p){
			//invalid prefix
			return 0;//??
		}
		if( !*(p+1) && cur->isWord)//the prefix itself is a word
			res[index++]=prefix;
		cur=cur->firstChild;
		p++;
	}

	string path=prefix;
	get_words(cur,res,index,maxNumOfResult, path);

	return index;
}
void Trie::insert(const char* word){
	if(!*word) return;
	const char* p=word;
	Node* parent=root;

	while(*p){
		if(!parent->firstChild || parent->firstChild->content > *p){
			Node* tmp=new Node(*p);
			tmp->sibling=parent->firstChild;
			parent->firstChild=tmp;
			parent=tmp;
		}
		else{//parent->firstChild is not NULL
			if(parent->firstChild->content == *p){
				parent=parent->firstChild;
				++p;
				continue;
			}

			Node* cur=parent->firstChild;
			while(cur->sibling && cur->sibling->content < *p ){
				cur=cur->sibling;
			}
			if( !cur->sibling || cur->sibling->content!=*p){
				Node* tmp=new Node(*p);
				tmp->sibling=cur->sibling;
				cur->sibling=tmp;
			}
			parent=cur->sibling;
		}

		++p;
	}
	parent->isWord=true;

}
int main()
{
	Trie trie;
	trie.insert("act");
	trie.insert("bar");
	trie.insert("ads");
	trie.insert("ac");
	int maxNumOfResult;
	cin>>maxNumOfResult;
	string *strArr=new string[maxNumOfResult];
	char* prefix=new char[20];
	cin>>prefix;
	int resultNum=trie.search(prefix,maxNumOfResult, strArr);
	cout<<"resultNum:"<<resultNum<<endl<<endl;
	for(int i=0;i<resultNum;++i){
		cout<<strArr[i]<<endl;
	}
}
