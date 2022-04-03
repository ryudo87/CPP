Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].


class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n<3) {
      return n;
    }
    
    int cur=1, pre=1;
    bool show_twice = false;
    while (cur<n) {
      if (A[cur]==A[cur-1] && show_twice ) {
        cur++;
        continue;
      }
      
      if (A[cur]==A[cur-1]) {
        show_twice = true;
      } else {
        show_twice = false;
      }
      A[pre] = A[cur];
      pre++;
      cur++;
    }
    
    return pre;
  }
};