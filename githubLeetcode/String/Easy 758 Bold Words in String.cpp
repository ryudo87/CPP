https://www.youtube.com/watch?v=rUNE3VVcXAs&list=PLLuMmzMTgVK49Hph4vV8DAzGZpj4azwmz&index=16

https://www.dropbox.com/s/s6y7g071ayfyudc/Screen%20Shot%202022-03-07%20at%209.32.22%20PM.png?dl=0

Idea: Check weather a char will be bolded or not. Try all possible substring of S, in words or not.
Try all substring of S, in words or not
n*(n-1)/2  substrings    Time: O(nL^2) L is max len of a word , Space: O(n) mark if each char is bold


class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        const int kMaxWordLen = 10;
        unordered_set<string> dict(words.begin(), words.end());
        
        int n = S.length();
        vector<int> bolded(n, 0);
        
        for (int i=0;i<n;++i) {
            for (int l=min(n-i, kMaxWordLen);l>=1;--l) {
                if (dict.count(S.substr(i, l))) {
                    std::fill(bolded.begin()+i, bolded.begin()+i+l, 1);
                    break;
                }
            }
        }
        
        string ans;
        for (int i=0;i<n;++i) {
            if (bolded[i] && (i==0 || !bolded[i-1])) ans += '<b>';
            ans += S[i];
            if (bolded[i] && (i==n-1 || !bolded[i+1])) ans += '</b>';
        }
        
        return ans;
    }
};




