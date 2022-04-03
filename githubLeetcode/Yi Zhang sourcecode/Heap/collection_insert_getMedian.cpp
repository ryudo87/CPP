
#include "all.h"

//Implement a collection that supports Insert() and GetMedian()

//Implement a collection that supports Insert() and GetMedian()
//come up with the annotated tree solution. Good candidates will quickly explain that GetMedian is O(log N) on a balanced tree using these annotations
//
//I want to see them define a Node (include left and right child counts) and handle the recursion well.
//
//2-heaps solution is my favorite:
//
//fibonacci heaps
//If you used Fibonacci heaps, insertion would be O(log n), due to the rebalancing.

template<class T>
class TwoHeap
{
	priority_queue<T,vector<T>,greater<T> > minpq;
	priority_queue<T> maxpq;
public:
	void insert(T val){
		if(minpq.size()==maxpq.size()){
			if(!maxpq.empty() && val < maxpq.top()){
				maxpq.push(val);
				minpq.push(maxpq.top());
				maxpq.pop();
			}
			else{
				minpq.push(val);
			}
		}
		else{
			if(!minpq.empty() && val > minpq.top()){
				minpq.push(val);
				maxpq.push(minpq.top());
				minpq.pop();
			}
			else{
				maxpq.push(val);
			}
		}
	}
	T GetMedian(){
		try{

			if(minpq.size()==maxpq.size()){
				return (minpq.top()+maxpq.top())/2;
			}
			else{
				return minpq.top();
			}

		}catch(exception& e){cerr<<e.what()<<endl;exit(1);}
	}
};
int main()
{
	TwoHeap<double> con;
	con.insert(3);
	con.insert(5);
	con.insert(9);
	cout<<con.GetMedian()<<endl;
	con.insert(6);
	cout<<con.GetMedian()<<endl;

	return 0;
}


//#include "all.h"

//Streaming Median
//
//The streaming median is computed using two heaps. All the numbers less than or equal to the current median are in the left heap,
//which is arranged so that the maximum number is at the root of the heap.
//All the numbers greater than or equal to the current median are in the right heap,
//which is arranged so that the minimum number is at the root of the heap. Note that numbers equal to the current median can be in either heap.
//
//
//Implement a collection that supports two operations: Insert(value) and GetMedian() returns (value)
//Solutions:
//¥	Unsorted array / linked list
//¥	Tangent: How do you grow the array, assuming all the elements must be contiguous in memory?
//¥	Insert is O(1)
//¥	GetMedian is O(N log N) if we sort the list first, O(N) if we use the Selection algorithm (CLRS section 9.3). If your candidate mentions the latter, great, but make sure they understand how it works.
//¥	This might be the right solution if calls to GetMedian are rare!
//¥	Sorted array / linked list
//¥	GetMedian is O(1) (assuming we keep a pointer to the middle)
//¥	Insert is O(N) because the elements must be shifted (array) or scanned (list)
//¥	Binary tree
//¥	Insert is O(log N)
//¥	GetMedian is O(1) if we keep a balanced tree of values and read the root -- this doesn't work
//¥	What balanced tree implementation is perfectly balanced? Red-black does not guarantee this. Therefore we need to keep explicit pointers to the median element and update this pointer on each insert, but this is non-trivial (we need to implement find-next-node and find-previous-node, given the median node; pretty easy to do if nodes have parent pointers).
//¥	What if we want the median of an even number of elements to be the mean of the middle two elements?
//¥	Need two pointers to two midmost elements, and need to update those pointers for insertions that are less than, greater than, or inbetween the two elements.
//¥	GetMedian is O(1) if one uses a threaded tree - i.e. where all nodes are simultaneously in a tree and a linked list. Inserting is done as normal binary tree insert and updating the linked list pointers from there can be done in constant time. GetMedian involves keeping a pointer to the median element, as well as tracking if the median is to the left, right, or dead center for updates.
//¥	GetMedian is O(N) if we traverse inorder to the midmost node
//¥	GetMedian is O(log N) if we annotate each node with the size of its children's subtrees (updating on insertion) and descend to the midmost node
//¥	Be sure to have the candidate work through a sample tree. Choose a tree for which "recurse to the larger subtree" doesn't always work, e.g., (in preorder) 7 4 2 1 3 6 5 9 8 11 10 (node 6 is the median and is the right child of node 4, but node 4 has more children to in its left subtree).
//¥	Skip list
//¥	GetMedian is O(1) if we keep a pointer to the median element
//¥	Insert is O(log N)
//¥	Pair of heaps, kept in balance (within 1 element of each other in size)
//¥	Left heap has lower 50%, top of the heap is the max of this set
//¥	Right heap has upper 50%, top of the heap is the min of this set
//¥	GetMedian is O(1) by reading the tops of the larger heap (or the average of the tops if they're even)
//¥	Insert is O(log N) by pushing onto the left or right heap (if less than or greater than the median value), the rebalancing the heaps if needed (by popping off of the larger and pushing onto the smaller)
//¥	This is a good coding question, assuming we provide a Heap (a.k.a. PriorityQueue) API.



double stream_median(int arr[],int n)
{
	priority_queue<int> q1;
	priority_queue<int,vector<int>, greater<int> > q2;
	for(int i=0;i<n;++i){
		if(q1.empty() || q1.top()>arr[i]){
			q1.push(arr[i]);
		}
		else{
			q2.push(arr[i]);
		}
		if(q1.size()<q2.size()){
			int t=q2.top();q2.pop();
			q1.push(t);
		}
		else if(q1.size()>q2.size()+1){
			int t=q1.top();q1.pop();
			q2.push(t);
		}
	}
	if(n%2){
		return q1.top();
	}
	else{
		return ((double)q1.top()+(double)q2.top())/2;
	}
}
double sortToGetMedian(int arr[],int n)
{
	if(!arr || 0==n) return 0;
	print_array<int>(arr,n,"before sort");
	sort(arr,arr+n);
	print_array<int>(arr,n,"after sort");
	if(1==n%2)	return arr[n/2];
	return ((double)arr[n/2-1]+(double)arr[n/2])/2;
}
TEST(stream_median, RANDOM)
{
	int *arr,n=0;
	for(int i=0;i<2;++i){
		randGenArr(arr,n);
		ASSERT_DOUBLE_EQ(sortToGetMedian(arr,n),stream_median(arr,n));
	}

}

