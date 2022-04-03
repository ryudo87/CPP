#include "all.h"

// https://gist.github.com/JunjieQi/6396410

//Search in Rotated Sorted Array
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
int search(int A[], int n, int target) {
   if(!A) return -1;
   int low=0,high=n-1;
   while(low<=high){
       int mid=(low+high)/2;
     
     if(A[mid]==target) {
       return mid;
     } else if(A[mid]<target){
 
       if(A[high]>=target||A[low]<A[mid]){
            low=mid+1;
       }
       else{
          high=mid-1;
       }
     
     } else{
            if(A[low]<=target||A[high]>A[mid]){
                  high=mid-1;
            }
            else{
               low=mid+1;
            }
       }
   }

   return -1;
}


//Submission Result: Accepted
class Solution {
public:
  int bi_search(int A[], int n, int target) {
    int low=0, high=n-1;
    while(low<=high) {
      int mid=(low+high)/2;
      if (A[mid] == target) {
        return mid;
      } else if (A[mid] > target) {
        high=mid-1;
      } else {
        low=mid+1;
      }
    }
    return -1;
  }
  int search(int A[], int n, int target) {
    if (n<1) {
      return -1;
    }
    
    int i=0, j=n-1, k=(n-1)/2;
    if (A[k] == target) {
      return k;
    }
    
    if (A[i] <= A[k]) {
      if (target<A[i] || target>A[k]) {
        int index = search(A+k+1, n-k-1, target);
        if (index == -1) return -1;
        return 1+k+index;
      } else {
        return bi_search(A, k+1, target);
      }
    } else {
      if (target<A[k] || target>A[j]) {
        return search(A, k, target);
      } else {
        int index = bi_search(A+k+1, n-k-1, target);
        if (index == -1) return -1;
        return index+k+1;
      }
    }
  }
};
