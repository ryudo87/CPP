class Solution {//DFS Time O(n*2^i) i is # of letters     Space O(n) + O(n*2^i) stack
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }
    
    void dfs(string& S, int i, vector<string>& ans) {
        if (i==S.length()) {
            ans.push_back(S);
            return;
        }
        dfs(S, i+1, ans);
        if (!isalpha(S[i])) return;
        S[i] = toggle(S[i]);
        dfs(S, i+1, ans);
        S[i] = toggle(S[i]);//back
    }
    char toggle (char c) {
        c^=(1<<5);
        return c;
    }
};
