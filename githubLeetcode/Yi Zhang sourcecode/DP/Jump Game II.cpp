#include "all.h"

//Jump Game II
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2.
//(Jump 1 step from index 0 to 1, then 3 steps to the last index.)





//My method:DP
// 48 milli secs
int jump(int A[], int n) {
    int* num=new int[n];
	memset(num,0,n*sizeof(int));

	int i=0,far=0;
	while(i<=far && i<n-1){
		if(i+A[i]>=n-1){
			return 1+num[i];
		}


		if(far<i+A[i]){
			int lastfar=far;
			far=i+A[i];
			for(int j=lastfar+1;j<=far;++j){
				num[j]=num[i]+1;
			}

		}
		++i;
	}
	return 0;
}


int main()
{
	int A[]={7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};

	cout<<jump(A,sizeof(A)/sizeof(A[0]))<<endl;
	return 0;
}
