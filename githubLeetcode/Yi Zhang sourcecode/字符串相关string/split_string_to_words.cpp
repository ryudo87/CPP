#include "all.h"
//
//split string to words
//A dictionary has n words.
//
//Given a string, find how many ways to split the string into words so that all words are in the dictionary.
//

string dict[]={"text","dog","cat","god","act","att","ack","attack","at"};
unsigned len=sizeof(dict)/sizeof(dict[0]);

vector<string> vec(dict,dict+len);
vector<int> cache;

int split_string_to_words(string str,unsigned pos)
{
	int num=0;
	if(str.empty()) return 0;
	cout<<"now split "<<str<<endl;
	for(unsigned i=1;i<=str.size();++i){
		string cursub=str.substr(0,i);
		cout<<"cursub:"<<cursub<<endl;
		if(find(vec.begin(),vec.end(),cursub)!=vec.end()){
			if(str.size()==i){
								num+=1;
								break;
			}
			if(-1==cache[pos+i+1]){
				cache[pos+i+1]=split_string_to_words(str.substr(i),pos+i);
			}
			num+=cache[pos+i+1];
		}
		for(unsigned i=0;i<cache.size();++i)
			cout<<cache[i]<<",";
		cout<<endl;
	}
	return num;
}

int main()
{
	cout<<len<<endl;

	sort(vec.begin(),vec.end());
	print_array<string>(dict, len, "dict");
	print_vector<string> (vec,"vec");
	char target[]="attack";
	cache.assign(sizeof(target),-1);

	cout<<"there are "<<split_string_to_words(target,0)<<" ways to split"<<endl;
	return 0;
}
