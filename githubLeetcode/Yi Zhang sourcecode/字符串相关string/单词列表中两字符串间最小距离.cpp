#include "stdafx.h"
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
#include <list>
#include <memory>
#include <ctime>
#include <hash_map>
using namespace std;

int find_shortest_dis()
{

	string wordlist[]={"a","b","c","d","b","e","a"};
    int min=sizeof(wordlist)/sizeof(string);
	int arrlen=min;
	
	map<string, list< int >  > map0;
	for(int i=0;i<arrlen;++i)
	{
		//pair<int,string> pa(i,wordlist[i]);
		map0[wordlist[i]].push_back( i);
	}
	string str1,str2;
	cin>>str1>>str2;

	list< int > list1=map0[str1];
	list< int > list2=map0[str2];
	list< int >::iterator it1=list1.begin();
	list< int >::iterator it2=list2.begin();
	while(it1!=list1.end()&&it2!=list2.end()){
		if(*it1<*it2){
			if(*it2-*it1<min){
				min=*it2-*it1;				
			}
			++it1;
		}
		else{
			min=min<*it1-*it2? min: ( *it1-*it2 )  ;
			++it2;
		}
	}


	return min;
}
int _tmain()
{
	cout<<find_shortest_dis()<<endl;
	return 0;
}


