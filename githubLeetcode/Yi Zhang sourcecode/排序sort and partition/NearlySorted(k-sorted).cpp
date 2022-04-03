

//Given an array of n unsorted integers and each number is at most k positions away from its final sorted position,
//give an efficient sorting algorithm. ???????  View Answers (3)

//Use minheap on first k elements, and extract min and insert the next element.
//Keep doing until the end of the array. This takes O(nlogk).


//Solution 1: divide the file into N/k pieces of size k, and sort each piece in O(k log k) time, say using mergesort.
//Note that this preserves the property that no element is more than k elements out of position.
//Now, merge each blocks of k elements with the block to its left.
//
//Solution 2: insert the first k elements into a binary heap. Insert the next element from the array into the heap, and delete the minimum element from the heap. Repeat.
//
//Problem 6. k-Sorting [25 points] (4 parts)
//
//An array A[1 : : : n] is said to be k-unsorted if each element’s index is at most k away from its
//
//index in the sorted array (assume that all elements in A are distinct). We will design two different
//
//algorithms to sort a k-unsorted array in O(n log k) time in this problem.
//
//(a) Let A[1 : : : n] be a k-unsorted array. Suppose you have a sorted array S containing the smallest i numbers in A[1 : : : k + i] and a data structure R containing
//
//the remaining numbers in A[1 : : : k + i]. What data structure (that you have learned in
//
//class) would you use to implement R so that you can obtain S and R for A[1 : : : k +
//
//i + 1] from S and R for A[1 : : : k + i] in O(log k) time?
//
//(b) [6 points] Use part (a) to give an O(n log k)-time algorithm for sorting a k-unsorted
//
//array.
//
//(c) [5 points] Now, we use the divide-and-conquer paradigm to solve the same problem.
//
//Suppose that you have recursively sorted A[1 : : : n=2] and A[n=2+1 : : : n]. Which are
//
//the only elements that might be out of their correct sorted position in A[1 : : : n]? How
//
//long would you take to sort them thereby obtaining the ﬁnal sorted array?
//
//(d) [7 points] Use part (c) to give an O(n log k)-time divide-and-conquer algorithm for
//
//sorting a k-unsorted array.

#include "all.h"
///TEST CASE:
//duplicates???
//int arr[]={3,2,3,4,5}
//int arr[]={1,2,3,4,5}
//int arr[]={2,5};
void k_Sorting(int arr[], int n,int k)
{
	if(!arr || n<=1 || k<=0) return;
	priority_queue<int,deque<int>,greater<int> > pq;
	for(int i=0;i<=k&&i<n;++i){
		pq.push(arr[i]);
	}
	for(int i=0,j=k+1;i<n && !pq.empty();++i){
		arr[i]=pq.top();pq.pop();
		if(j<n){
			pq.push(arr[j]);
			++j;
		}
	}

}
