
//Search in Rotated Sorted Array
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//20ms
int search(int A[], int n, int target) {
       if(!A) return -1;
       int low=0,high=n-1;
       while(low<=high){
           int mid=(low+high)/2;
           if(A[mid]==target) return mid;
           else if(A[mid]<target){
                if(A[high]>=target||A[low]<A[mid]){
                      low=mid+1;
                }
                else{
                    high=mid-1;
                }
           }
           else{
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
