
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
using namespace std;

int arr[]={6,2,8,1};
vector<int> list(arr,arr+4);

void swap(int i,int j)
{
	int temp=list[i];
	list[i]=list[j];
	list[j]=temp;
}
void filterdown(int cur,int last)
{
	int child=2*cur+1;
	int temp=list[cur];
	while(child<=last)
	{
		if(child<last && list[child]<list[child+1])
			child++;
		if(temp>=list[child])
			break;
		else
		{
			list[cur]=list[child];
			cur=child;
			child=2*child+1;
		}
	}
	list[cur]=temp;
}
int main()
{


	for(int i=list.size()/2-1;i>=0;i--)
		filterdown(i,list.size()-1);

	for(int i=list.size()-1;i>0;i--)
	{
		swap(0,i);
		filterdown(0,i-1);
	}

}



