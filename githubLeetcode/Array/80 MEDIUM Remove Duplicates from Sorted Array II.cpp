#include "all.h"
//Remove Duplicates from Sorted Array II
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array A = [1,1,1,2,2,3],
//
//Your function should return length = 5, and A is now [1,1,2,2,3].
int removeDuplicates(int A[], int n) {
	if(n<=1) return n;
	int blank=0, last=A[0],cnt=1;
	for(int i=1;i<n;++i){
		if(A[i]==last){
			A[i-blank]=A[i];
			cnt++;
			if(cnt>=3)
				blank++;
		}
		else{
			A[i-blank]=A[i];
			last=A[i];
			cnt=1;
		}
	}

	return n-blank;
}

int main()
{

	return 0;
}
