


//Max sliding window 待做	May. 21, 2010 11:49pm
//Given a set of numbers and sliding window of size k, find the max for each window.
//
//For example:
//Input:
//1 2 10 3 5 12
//k = 3
//
//[1 2 10] 3 5 12 - 10
//1 [2 10 3] 5 12 - 10
//[1 2 [10 3 5] 12 - 10
//1 2 10 [3 5 12] - 12
//Output:
//10 10 10 12
//
//I will give candidates more examples to make sure they understand the question. There are several ways to solve this question in O(nk).
//Of course the best solution is in O(n) time using deque. Following is the code I wrote sometime back to solve it using deque:
//
//
//// Maintain deque such that:
//// - The front of the deque has the maximum element for the current window.
//// - It has only elements that have "can" make it to output.
//// Solution is O(n) - we pop any element only once.
//
//
//void GetMaxInSlidingWindow(const vector<int>& input, int window, vector<int>* output) {
//  deque<int> d;
//  int index = 0;
//  for (vector<int>::const_iterator it = input.begin();
//       it != input.end(); ++it) {
//    // If deque is full, we will have to pop one
//    // And don't pop any initially, until first window is filled up.
//    if ((index-window >= 0) && (d.front() <= (index-window))) {
//      d.pop_front();
//    }
//
//    // Now pop all useless elements, those that are less than current element,
//    // since they can never make it to output.
//    while (!d.empty() && (input.at(d.back()) < *it)) {
//      d.pop_back();
//    }
//
//    // Push the current element.
//    d.push_back(index);
//    // The first element in the deque is the max element for the
//    // current window.
//    if (index >= window-1) {
//      output->push_back(input.at(d.front()));
//    }
//    index++;
//  }
//}


#include "all.h"
#include "tree.h"
int arr[]={9,1,7,3,5};
int len=sizeof(arr)/sizeof(arr[0]);

list<int> max_sliding_window(int k)
{
	list<int> res;
	deque<int> dq;

	for(int i=0;i<len;i++){
		while(!dq.empty() && dq.back() < arr[i]){
			dq.pop_back();
		}
		dq.push_back(arr[i]);
		if(i>=k && arr[i-k] == dq.front()){
			dq.pop_front();
		}
		if(i>=k-1) res.push_back(dq.front());
	}

	return res;
}

int main()
{
	list<int> res=max_sliding_window(3);
	for(list<int>::const_iterator it=res.begin();it!=res.end();++it){
		cout<<*it<<endl;
	}

	return 1;
}
