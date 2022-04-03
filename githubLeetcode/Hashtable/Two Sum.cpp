#include "all.h"





// Given an array of integers, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

vector<int> twoSum(vector<int> &numbers, int target) {
  set<int> numSet;
  vector<int> indexArr;
  
  for (int i=0; i<numbers.size(); ++i) {
    if (numSet.find(target-numbers[i]) != numSet.end()) {
      for (int j=0; j<i; ++j) {
        if (numbers[j] + numbers[i] == target) {
          indexArr.push_back(j+1);
        }
      }
      
      indexArr.push_back(i+1);
      return indexArr;
    }
    
    numSet.insert(numbers[i]);
  }
  
  return indexArr;
}