#include "all.h"


//Longest Palindromic Substring
//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
O(n^2)
string longestPalindrome(string s) {
	int curMax=0;
	int sz=s.size();
	string res;
	for(int i=0;i<sz;++i){
		int beg,end;
		for(beg=i-1,end=i+1;beg>=0&&end<sz;beg--,end++){
			if(s[beg]!=s[end]){
				break;
			}
		}
		if(end-beg-1>curMax){
			curMax=end-beg-1;
			res=s.substr(beg+1,curMax);
		}

		for(beg=i,end=i+1;beg>=0&&end<sz;beg--,end++){
			if(s[beg]!=s[end]){
				break;
			}
		}
		if(end-beg-1>curMax){
			curMax=end-beg-1;
			res=s.substr(beg+1,curMax);
		}
	}

	return res;
}


Brute force solution, O(N3):
The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome. There are a total of C(N, 2) such substrings (excluding the trivial solution where a character itself is a palindrome).

Since verifying each substring takes O(N) time, the run time complexity is O(N3).

Dynamic programming solution, O(N2) time and O(N2) space:
To improve over the brute force solution from a DP approach, first think how we can avoid unnecessary re-computation in validating palindromes. Consider the case “ababa”. If we already knew that “bab” is a palindrome, it is obvious that “ababa” must be a palindrome since the two left and right end letters are the same.

Stated more formally below:

Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.
Therefore,

P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )
The base cases are:

P[ i, i ] ← true
P[ i, i+1 ] ← ( Si = Si+1 )
This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on…

This gives us a run time complexity of O(N2) and uses O(N2) space to store the table.


string longestPalindromeDP(string s) {
  int n = s.length();
  int longestBegin = 0;
  int maxLen = 1;
  bool table[1000][1000] = {false};
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  return s.substr(longestBegin, maxLen);
}


A simpler approach, O(N2) time and O(1) space:
In fact, we could solve it in O(N2) time without any extra space.

We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.

You might be asking why there are 2N-1 but not N centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as “abba”) and its center are between the two ‘b’s.

Since expanding a palindrome around its center could take O(N) time, the overall complexity is O(N2).

string expandAroundCenter(string s, int c1, int c2) {
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l+1, r-l-1);
}

string longestPalindromeSimple(string s) {
    int n = s.length();
    if (n == 0) return "";
    string longest = s.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n-1; i++) {
        string p1 = expandAroundCenter(s, i, i);
        if (p1.length() > longest.length())
            longest = p1;
        
        string p2 = expandAroundCenter(s, i, i+1);
        if (p2.length() > longest.length())
            longest = p2;
    }
    return longest;
}
