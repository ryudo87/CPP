#include "stdafx.h"
#include <cstdio>
#include <cassert>
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

struct Box
{
	int w;int h;int d;
	bool operator ==(const Box& b){
		if(w==b.w && h==b.h && d==b.h) return true;
		return false;
	}
	bool operator <=(const Box& b){
		if(w<=b.w || h<=b.h || d<=b.h) return true;
		return false;
	}
};
#define N 3
Box boxs[]={{2,2,2},{3,4,5},{1,5,6}};

vector<int> maxDep[N];
int maxVal[N];

int build_tallest_stack(int bottom,bool used[],vector<int>& box_vec)
{	
	if(maxVal[bottom]!=0){
		box_vec.insert(box_vec.end(),maxDep[bottom].begin(),maxDep[bottom].end());     
		return maxVal[bottom];
	}
	
	int max=0;
	for(int i=0;i<N;++i){
		if( used[i]==true || boxs[bottom] <= boxs[i]) continue;

		used[i]=true;
		box_vec.push_back(i);
		int t=build_tallest_stack(i,used,box_vec);//ÒÔiÎªbottom
		used[i]=false;

		if(max<t) {max=t;maxDep[bottom]=box_vec;maxVal[bottom]=t+boxs[bottom].d;}
		box_vec.pop_back();
	}
		
	return boxs[bottom].d+max;
}
void main(void)   
{   
	vector<int> box_vec;
	bool used[N]={false};
	int max=0,index=0;
	for(int i=0;i<N;++i){
		used[i]=true;
		int t=build_tallest_stack(i,used,box_vec);

		if(maxVal[i]==0){
			maxDep[i]=box_vec;
			maxVal[i]=t;
		}
		if(max<t) {
			max=t;
			index=i;
			
		}
		used[i]=false;
	}

	cout<<index<<endl;
	for(size_t i=0;i<maxDep[index].size();++i)
		cout<<maxDep[index][i]<<endl;
	cout<<maxVal[index];

}