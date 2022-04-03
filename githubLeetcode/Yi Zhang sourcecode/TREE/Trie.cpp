
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

class Trie
{
protected:
	struct node{
		char* word;
		node* branch[26];
		node();
	};
	node* root;

public:
	Trie();
	int search(const char* word) const;
	int insert(const char* word);
	int remove(const char* word);
	void printall(char *pre, node* p);
	void printpre(char *pre);
};
Trie::Trie():root(NULL){}
Trie::node::node()
{
	word=NULL;
	for(int i=0;i<26;++i)
		branch[i]=NULL;
}

int Trie::search(const char* word) const
{
	char char_code;
	node* location=root;
	while(location!=NULL&&*word!=0)
	{
		if(*word>='a'&&*word<='z')
			char_code=*word-'a';
		else return 0;
		location=location->branch[char_code];
		word++;
	}

	if(location!=NULL && location->word!=NULL)
		return 1;
	else	return 0;
}

int Trie::insert(const char* word)
{
	cout<<"insert:"<<word<<endl;
	int result=1;
	if(!root)
		root=new node;
	char char_code;
	node* location=root;
	while(location && *word)
	{
		if(*word>='a'&&*word<='z')
			char_code=*word-'a';
		else return 0;
		if(location->branch[char_code]==NULL)
			location->branch[char_code]=new node;
		location=location->branch[char_code];
		word++;
	}
	if(location->word!=NULL)
		result=0;
	else
	{
		location->word=new char[strlen(word)+1];
		strcpy(location->word,word);
	}
	return result;
}

int Trie::remove(const char* word)
{
	cout<<"delete"<<word<<endl;
	int result=1;
	char char_code;
	node* location=root;
	while(location && *word)
	{
		if(*word>='a'&&*word<='z')
			char_code=*word-'a';
		else return 0;
		location=location->branch[char_code];
		word++;

	}
	if(location&&location->word)
	{
		delete location->word;
		location->word=NULL;
	}
	else result=0;

	return result;
}
void Trie::printall(char *pre,node* p)
{
	if(p->word){
		cout<<pre<<endl;
	}
	for(int i=0;i<26;++i)
	{
		if(p->branch[i]!=NULL)
		{
			char ch='a'+i;
			char *prestr=new char[strlen(pre)+2];
			sprintf(prestr,"%s%c",pre,ch);
			printall(prestr,p->branch[i]);
			delete[] prestr;
		}
	}
}

void Trie::printpre(char *pre)
{
	char char_code;
	char *p=pre;
	node* location=root;
	while(location&& *pre)
	{
		if(*pre>='a'&&*pre<='z')
			char_code=*pre-'a';
		else return;
		location=location->branch[char_code];
		pre++;
	}

	if(location)
		printall(p,location);
	return;
}
int main()
{
	Trie t;
//	t.insert("blue");
//	t.insert("blur");
//	t.insert("car");
//	t.insert("cat");
//	t.insert("caw");
//	t.insert("coin");
	t.insert("coim");
	t.remove("coim");
	t.printpre("");
	cout<<t.search("cat")<<endl;
	t.printpre("c");
}
