#include "all.h"




//给一个integer array，允许duplicates，而且其中某个未知的integer的duplicates的个数占了整个array的一大半。如何有效的找出这个integer？



//Find majority element in an array

// Let T [1..n] be an array of n integers. An integer is a majority element in T if it appears
// strictly more than n/2 times in T. This paper is concerned with finding an algorithm that
// can decide whether an array T [1..n] contains a majority element, and if so, find it. The
// algorithm runs in linear time in the worst case.
// Also, the only comparisons allowed between the elements of T are tests of equality.  This
// means, there does not exist an order relation between the elements of the array.
// Input  : An input array, unsorted, of the type T [i..j].
// Output : The majority element ele, if it exists. If a majority element does not exist, the algorithm returns a null.







// returns -1 if there is no element that is the majority element, otherwise that element

// funda :: if there is a majority element in an array, say x, then it is okay to discard
// a part of that array that has no majority element, the remaining array will still have
// x as the majority element

// worst case complexity :  O(n)

int findMajorityElement(int * arr, int size) {
     int count = 0,i, majorityElement;
     for (i = 0 ;  i < size ; i++) {
        if(count == 0) {
            majorityElement = arr[i];
        }
        if(arr[i] == majorityElement)
           count++;
        else
           count--;
     }
     count = 0;
     for (i=0; i < size ; i++) {
          if (arr[i] == majorityElement) {
                count++;
          }
     if ( count > size/2) {
          return majorityElement;
     }
     else return -1;
}

    
    //Design an algorithm that, given a list of n elements in an array,
    //finds all the elements that appear more than n/3 times in the list. The algorithm should run in linear time ( n >=0 )
    
    //You are expected to use comparisons and achieve linear time.
    //No hashing/excessive space/ and don't use standard linear time deterministic selection algo
    
    
    void find_over_one_third(int arr[], int n)
    {
        int one,two,cnt1=0,cnt2=0;
        for(int i=0;i<n;++i){
            if(cnt1==0){
                cnt1=1;one=arr[i];
            }
            else if(one==arr[i]){
                cnt1++;
            }
            else if(cnt2==0){
                cnt2=1;two=arr[i];
            }
            else if(two==arr[i]){
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
                if(cnt1==0 && cnt2!=0){
                    one=two;cnt1=cnt2;cnt2=0;
                }
            }
        }
        
        {
            cnt1=0;
            cnt2=0;
            for(int i=0;i<n;++i){
                cnt1+= (one==arr[i]?1:0);
                cnt2+= (two==arr[i]?1:0);
            }
            if(cnt1>(n/3)) cout<<one<<endl;
            if(cnt2>(n/3)) cout<<two<<endl;
        }
    }

int main()
{
	int arr[]={1,2,3,5};
	cout<<findMajorityElement(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
}
