#include "all.h"


//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//]]
//Given input array A = [1,1,2],
//
//Your function should return length = 2, and A is now [1,2].


class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n ==0) return 0;
    int index = 0;
    for(int i =0;i<n; i++)
    {
      if(A[index] == A[i])
      {
        continue;
      }
      index++;
      A[index] = A[i];
    }
    return index+1;
  }
};


class Solution {//Greedy:try to match prefix of A and suffix of B as much as possible
public: //And then check whether middle part of A or B is palindrome
    auto isPalindrome(const string& s, int i, int j) {
        while(i<j&&s[i] == s[j]) ++i, --j;
        return i>=j;
    }
    bool checkPalindromeFormation(string a, string b) {
        auto checkPalindromeImp = [=] (const string& a, const string& b) {
            int i=0, j=a.length()-1;
            while (i<a.length() && a[i] == b[j]) {++i, --j;}
            return isPalindrome(a, i, j) || isPalindrome(b, i, j);
        };
        return checkPalindromeImp(a, b) || checkPalindromeImp(b, a);
    }
};
