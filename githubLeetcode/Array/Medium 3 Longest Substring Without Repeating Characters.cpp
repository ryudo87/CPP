#include "all.h"

//Longest Substring Without Repeating Characters

//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring
//without repeating letters for "abcabcbb" is "abc",
//which the length is 3.
//For "bbbbb" the longest substring is "b", with the length of 1.



//O(2n)--128 milli secs
//sliding window
int lengthOfLongestSubstring(string s)
{
	map<char,int> hash;
	int start=0,n=s.size(), maxlen=0;
	int i;
	for( i=0;i<n;++i){
		if(hash.find(s[i])!=hash.end() && hash[s[i]]>=start) {
			maxlen=(maxlen<i-start)?i-start:maxlen;
			start=hash[s[i]]+1;
		}
		hash[s[i]]=i;
	}
	maxlen=(maxlen<i-start)?i-start:maxlen;
  
	return maxlen;
}




int findLongestSubstrWithoutDup(string s) {
  if (s.size()<=1) {
    return s.size();
  }
  
  int l=0, r=0, cur_longest_len = 1;
  map<char, int> char2index;
  
  while(r<s.size()) {
    if (char2index.find(s[r]) != char2index.end() && char2index[s[r]] >= l) {
      l = char2index[s[r]]+1;
      char2index[s[r]] = r;
      ++r;
      continue;
    }
    
    int cur_len = r-l+1;
    cur_longest_len = cur_len > cur_longest_len ? cur_len : cur_longest_len;
    
    char2index[s[r]] = r;
    ++r;
  }
  
  return cur_longest_len;
}

//DP:
//http://blog.csdn.net/ju136/article/details/6958018
//52ms
//int lengthOfLongestSubstring(string s)
//{
//	const int len = s.length();
//	int *dp = new int[len+2];
//	int last[256];
//	for (int i = 0; i < 256; ++i) last[i] = len;
//	dp[len] = len;
//
//	for (int i = len - 1; i >= 0; --i)
//	{
//		dp[i] = min(dp[i+1], last[s[i]] - 1);
//		last[s[i]] = i;
//	}
//
//	int ans = -1;
//	for (int i = 0; i < len; ++i)
//	{
//		const int ret = dp[i] - i;
//		ans = ans > ret ? ans : ret;
//	}
//	delete [] dp;
//	return ans + 1;
//}



int main()
{
    //"abcabcbb"
	cout<<lengthOfLongestSubstring("abcabcbb")<<endl;
	return 0;
}
