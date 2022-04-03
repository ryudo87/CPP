#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <deque>
#include <memory>
#include <ctime>
#include <typeinfo>
using namespace std;

//给一个整数数组，其中包含重复的数字，
template<int len>
void find_repetitive_number(int arr[])
{
	map<int,int> map0;
	for(int i=0;i<len;++i){
		if(map0.find(arr[i])==map0.end())
			map0[arr[i]]=1;
		else cout<<arr[i]<<endl;
	}
}

//出随机字符组成的两个字符串，判断是否由相同的字符组成。
//例如abbffgg==fgbagfb 

bool findif_same_chars(string a,string b)
{
	set<char> set1,set2;
	for(int i=0;i<a.length();++i){
		set1.insert(a[i]);
	}
	for(int i=0;i<b.length();++i){
		set2.insert(b[i]);
	}

	set<char>::iterator ita=set1.begin(),itb=set2.begin();
	while(ita!=set1.end()&&itb!=set2.end()){
		if(*ita!=*itb) return false;
		ita++;itb++;
	}
	if(ita==set1.end()&&itb==set2.end()) return true;
	return false;
}
//写一个判断找出字符串中最长的对称字串。
//例如：ababba中最长的对称子串为abba 
//可能出现多个同长的对称子串
void find_longest_symmetric_str(char* str,int len)
{
	int cur=0;
	int max_len=1;
	int start=0,end=0;
	while(cur<len){
		int prev=cur-1,next=cur+1,tmpMax=1;
		while(prev>=0&&next<len&&str[prev]==str[next]){
			tmpMax+=2;
			--prev;
			++next;
		}
		if(tmpMax>max_len) 
		{
			max_len=tmpMax;
			start=prev+1;
			end=next-1;
		}

		//even length of symmetric string
		prev=cur,next=cur+1,tmpMax=0;
		while(prev>=0&&next<len&&str[prev]==str[next]){
			tmpMax+=2;
			--prev;
			++next;
		}
		if(tmpMax>max_len) 
		{
			max_len=tmpMax;
			start=prev+1;
			end=next-1;
		}

		cur++;
	}

	for(int i=start;i<=end;i++)
		cout<<str[i];

}

int main(int argc, _TCHAR* argv[])
{

	
	string a="abfg",b="faagfb";
	find_longest_symmetric_str("bbabadddd",9);

	
	//cout<<findif_same_chars(a,b)<<endl;
	//int arr[]={2,3,2,4,9,0,2,3};
	//find_repetitive_number<sizeof(arr)/sizeof(*arr)>(arr);
		return 0;
}
