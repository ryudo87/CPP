
题目1. LIS. 一个任意的数组，找出一个严格单调递增的最长子序列。
例如: {3,0,1,7,2,4,5,9} –> output： {0, 1, 2, 4, 5, 9}
很简洁巧妙的算法，能在O(N log N)时间和O(N)空间做出来！方法就是始终保持一个单
增的序列，然后新来的数如果比当前最大还大就append在后面，否则在单增序列里面做
binary search，替换相应位置的数。



#include "all.h"
#include "arrayOP.h"



#define MAX 10

int arr[]={8,3,1};
int n=sizeof(arr)/sizeof(arr[0]);

int longest_increasing_subsequence()
{
	int seq_tail[MAX],index=1;
	memset(seq_tail,0,sizeof(int)*MAX);seq_tail[0]=-1;
	for(int i=0;i<n;++i){
		if(arr[i]>seq_tail[index-1]){
			seq_tail[index++]=arr[i];
		}
		else{
			int mid=(index-1)/2,begin=0,end=index-1;
			while(begin<end){
				if(arr[i]>seq_tail[mid]&&arr[i]<seq_tail[mid+1]){
					seq_tail[mid+1]=arr[i];break;
				}
				else if(arr[i]<seq_tail[mid])	end=mid;
				else begin=mid+1;
				mid=(begin+end)/2;
			}
			if(begin==end&&end<index-1){
				if(arr[i]>seq_tail[begin]&&arr[i]<seq_tail[begin+1]){
					arr[begin+1]=arr[i];
				}
			}
			print_array(arr+begin,end-begin+1,"arr");
		}
		print_array(seq_tail,index,"seq_tail");
	}

	return index-1;
}
int main()
{
cout<<longest_increasing_subsequence()<<endl;
	
}
