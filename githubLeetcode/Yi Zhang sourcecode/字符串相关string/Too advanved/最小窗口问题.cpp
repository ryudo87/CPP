#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <memory>
#include <typeinfo>
using namespace std;
#define Max 100;

struct wordloc
{
	string name;
	int loc;
	wordloc(string s,int index=-1):name(s),loc(index){}
};

int min_window()
{
	string keywords[]={"bat", "spring", "dog"};
	vector<string> keyvec(keywords,keywords+3);
	vector<wordloc> arr;
	map<string,int> keycount;

	ifstream inf("words.txt");
	string word;
//	for(size_t i=0;i<keyvec.size();i++)
//		keycount[keywords[i]]=0;

	for(map<string, int>::iterator it=keycount.begin();it!=keycount.end();it++)
		cout<<it->first<<it->second<<endl;

	int index=0;
	while(inf>>word)
	{
		if(find(keyvec.begin(),keyvec.end(),word)!=keyvec.end())
		{

			wordloc tmp(word,index);
			arr.push_back(tmp);
		}
		index++;
	}
	size_t start=0,end=0;//??
	int minStart=0,minEnd=0,minLen=Max;


	while(end<arr.size()){

		while(end<arr.size()){
			if(keycount.size()==3){
							break;
			}

			for(map<string, int>::iterator it=keycount.begin();it!=keycount.end();it++)
										cout<<it->first<<it->second<<endl;

			if(keycount.find(arr[end].name)!=keycount.end())
				keycount[arr[end].name]++;
			else keycount[arr[end].name]=1;


			for(map<string, int>::iterator it=keycount.begin();it!=keycount.end();it++)
							cout<<it->first<<it->second<<endl;
			++end;
		}
		--end;
		if(minLen>arr[end].loc-arr[start].loc){
			minLen=arr[end].loc-arr[start].loc;
			minStart=arr[start].loc;
			minEnd=arr[end].loc;
		}


		if(keycount[arr[start].name]==1){
			keycount.erase(arr[start].name);

			for(map<string, int>::iterator it=keycount.begin();it!=keycount.end();it++)
				cout<<it->first<<it->second<<endl;
			++end;
		}
		else
			--keycount[arr[start].name];
		++start;
	}




	cout<<"start:"<<minStart<<endl;
	cout<<"end:"<<minEnd<<endl;
	cout<<"minLen:"<<minLen<<endl;

	return minLen;
}
int main()
{

	int ret=min_window();

}





