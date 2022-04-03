#include "all.h"

//3Sum Closest
//Given an array S of n integers, find three integers in S
//such that the sum is closest to a given number, target. Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
//
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//test case:
//<3 numbers
//0,0,0
//==target
//<target
//>target
//overflow?
//44 milli secs
int threeSumClosest(vector<int> &num, int target) {
	sort(num.begin(),num.end());
	int sum=num[0]+num[1]+num[n-1],n=num.size();

	for(int i=0;i<n-2;++i){
		int j=1+i,k=n-1;

		while(j<k){
			int t=num[i]+num[j]+num[k];
			if(abs(target-t)<abs(target-sum)){
				sum=t;
			}
			if(target==t){
				return sum;
			} else if(t<target){
				++j;
			} else{
				--k;
			}
		}

	}
	return sum;
}



