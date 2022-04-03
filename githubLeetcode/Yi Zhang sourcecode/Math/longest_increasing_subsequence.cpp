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
		else{//binary search
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
