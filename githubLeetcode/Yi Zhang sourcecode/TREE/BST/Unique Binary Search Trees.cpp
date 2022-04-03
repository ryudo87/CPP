#include "all.h"

//Unique Binary Search Trees Total Accepted: 15408 Total Submissions: 43155 My Submissions
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3

//Submission Result: Accepted
map<int, int> treeNum;

int numTrees(int n) {
  
  if (n<=1) {
    return 1;
  }
  
  if (treeNum.find(n) != treeNum.end()) {
    return treeNum[n];
  }
  int total = 0;
  for (int i=1; i<=(n+1)/2; ++i) {
    int left_num = numTrees(i-1);
    int right_num = numTrees(n-i);
    
    if (n%2 == 1 && i == (n+1)/2) {
      total += left_num * right_num;
    } else {
      total += 2*left_num * right_num;
    }
  }
  
  treeNum[n] = total;
  return total;
}


