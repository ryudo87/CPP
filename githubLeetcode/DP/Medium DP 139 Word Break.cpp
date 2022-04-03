//optimized 2019
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        vector<int> memo(s.size()+1, -1);
        
        return wordBreakHelper(s, 0, memo, wordSet);
    }
    
    //check if s[start] to s[n-1] is in wordSet
    bool wordBreakHelper(string s, int start, vector<int>& memo, const unordered_set<string>& wordSet) {
        // cout<<"start:"<<start<<endl;
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start] == 1;
        
        memo[start] = 0;//must init to 0
        for (int i=start+1;i<=s.size();++i) {
            string temp = s.substr(start, i-start); //s[start...i-1]
            if (0 == wordSet.count(temp)) continue;
            
            //s[start...i-1] is in wordSet, then check s[i...n-1]
            memo[i] = wordBreakHelper(s, i, memo, wordSet);//i can be s.size(), thus memo.size()==s.size()+1
            if (memo[i]) {
                memo[start] = 1;
                break;
            }
        }
        
        return memo[start];
    }
};

///2019
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> memo(n+1, -1);
        set<string> wordSet;
        for (auto word:wordDict) {
            wordSet.insert(word);
        }
        
        return wordBreakHelper(s, 0, memo, wordSet);
    }
    
    bool wordBreakHelper(string s, int start, vector<int>& memo, const set<string>& wordSet) {
        // cout<<"start:"<<start<<endl;
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start] == 1;
        
        memo[start] = 0;
        for (int i=start+1;i<=s.size();++i) {
            string temp = s.substr(start, i-start);
            if (wordSet.count(temp)) {
                // cout<<"temp:"<<temp<<endl;
                bool res = wordBreakHelper(s, i, memo, wordSet);
                memo[i] = res;
                if (res) {
                    memo[start] = 1;
                    break;
                }
            } 
        }
        
        return memo[start];
    }
};
//////////


leetcode Question: Word Break I
Word Break I
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".



Analysis:
First thought is DFS (depth first search), searching every dict elements, if matched go to next position of s, until find the last match. Consider a very long s has a bunch of "a" and other letters, and the dict has "a", the searching will be pretty slow then.

Note that the problem asked for "if or not", which means we don't need to know which dicts compose string s, but only a "true/false" result.

Instead of search each element in the dict, search every position of the string is another way:
Say mp[i][j]=true if S[i to j] can be found in dict, mp[i][j]=false otherwise.  In this way, we now have a matrix (actually upper triangle of the matrix) which shows the initial matching of string S.

Next step, the question becomes:  find the value of mp[0][s.size()-1]. How to determine mp[i][j]?
We can see that, for all the mp[i][j]=false, if there exists a k (i<=k<j), mp[i][k]==true and mp[k+1][j]==true, then mp[i][j]=true. This means, if s[i to k] can be found in the dict, and, s[k+1 to j] can also be found in the dict, then s[i to j] is a valid match. In the code, just set mp[i][j]=mp[i][k]&&mp[k+1][j] will work well.

The complexity of this problem is O(n^3), where n is the length of the original string.




bool wordBreak(string s, unordered_set<string> &dict) {
  if (s.empty()) {
    return true;
  }
  
  vector<bool> flag(s.length()+1,false);
  flag[0]=true;
  
  for (int end=1; end<=s.length(); end++) {
    for (int beg=0; beg<end; ++beg) {
      
      if (flag[beg] && (dict.find(s.substr(beg, end-beg)) != dict.end()) ) {
        flag[end]=true;
        cout<<"flag update:"<<end<<endl;
        break;
      }
    }
  }
  
  return flag[s.length()];
}


int main() {
  unordered_set<string> myset({"a","abc","b","cd"});
  wordBreak("abcd", myset);
  
}




