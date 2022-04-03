#include "all.h"

//Anagrams
//Given an array of strings, return all groups of strings that are anagrams.
//
//Note: All inputs will be in lower-case.

//test case: 1 empty string 2 same strings
//204 milli secs
vector<string> anagrams(vector<string> &strs) {
	vector<string> res;
	map<string, int> strmap;
	for(int i=0;i<strs.size();++i)
	{
		string tmp=strs[i];
		if(tmp.empty()) continue;
		sort(tmp.begin(),tmp.end());
		if(strmap.find(tmp)!=strmap.end()){
			res.push_back(strs[i]);
			if(strmap[tmp]!=-1){
				res.push_back(strs[strmap[tmp]]);
				strmap[tmp]=-1;
			}
		}
		else{
			strmap[tmp]=i;
		}
	}


	return res;
}





