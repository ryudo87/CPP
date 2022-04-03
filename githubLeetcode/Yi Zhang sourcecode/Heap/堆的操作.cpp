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
using namespace std;
class Heap
{
public:
	int arr[6];
	int len;
	
	void insert(int i){
		if(len>=6) return;
		arr[len++]=i;
		int cur=len-1;
		while(cur>0){
			int parent=(cur-1)/2;
			if(arr[parent]>arr[cur]){	
				arr[cur]=arr[parent];
				cur=parent;
			}
			else break;
		}
		arr[cur]=i;
	}
	void erase()
	{
		if(len==0) return;
		
		int temp=arr[len-1];
		arr[--len]=-1000;
		int cur=0,child=1;
		while(child<len){
			if(child+1<len && arr[child+1]<arr[child])
				++child;
			if(arr[child]>=temp) break;
			arr[cur]=arr[child];
			cur=child;
			child=2*cur+1;
		}
		arr[cur]=temp;
	}
};

int main()
{
	Heap heap;
	heap.len=0;
	heap.insert(8);
	heap.insert(5);
	heap.insert(3);
	heap.insert(9);
	heap.erase();
	return 0;
}


