#include "all.h"

//3Sum
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.



//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)


//目前的O(n^2)解法是，首先对集合进行排序，然后对于每一个元素，让其后的元素从首尾逼近需求解0，
//input			mine				correct
//[0,0,0,0]		[[0,0,0],[0,0,0]]	[[0,0,0]]
//为了避免重复记录相同的三元组,在排序好的数组中搜索时每次移指针要跳过连续相同值的区块.



//Submission Result: Accepted
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > res;
	sort(num.begin(),num.end());
  
	int n=num.size();
  
	for(int i=0;i<n-2;++i){
		if(num[i]>0) break; // if in this loop, the min > 0, then quit
    
		int j=i+1,k=n-1;
		
    while(j<k){
			if(num[i]+num[j]+num[k]==0){
        vector<int> zero_vec{num[i], num[j], num[k]};
        res.push_back(zero_vec);
        
        while (j<k && num[j]==num[j+1]) {
          ++j;
        }
        while (j<k && num[k-1]==num[k]) {
          --k;
        }
        
				++j;--k;
			} else if(num[i]+num[j]+num[k]>0){
				--k;
			} else{
				++j;
			}
      
    }
    
    while (i<n-2 && num[i]==num[i+1]) {
      ++i;
    }
  }
  
  return res;
}










