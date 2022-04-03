class Solution {//Brute Force:
public://Time: O((S+L)*W)   Space: O(1)
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        unordered_map<string, bool> m;//cache dup words frequency
        for (const string& word: words) {
            auto it = m.find(word);
            if (it == m.end()) {
                m[word] = isMatch(word, S);
            }
            ans += m[word] ? 1 : 0;
        }
        return ans;
    }
    
    bool isMatch(const string& word, const string& S) {
        int start = 0;
        for (const char c : word) {
            bool found = false;
            for (int i=start;i<S.length();++i) {
                if (S[i] == c) {
                    found = true;
                    start = i+1;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};


class Solution {//Indexing + binary search: map S to {char: [indices]} "acbca" -> pos = {'a':[0,4], 'b':[2], 'c':[1,3]}
public://Time: O(S) + O(W*L*Log(S))   Space: O(S)
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> pos(128);
        for (int i=0;i<S.length();++i)
            pos[S[i]].push_back(i);
        
        int ans = 0;
        for (const string& word : words)
            ans += isMatch(word, pos) ? 1 : 0;
        return ans;
    }
    
private:
    unordered_map<string, bool> m_;
    bool isMatch(const string& word, const vector<vector<int>>& pos){
        if (m_.count(word)) return m_[word];//previously checked
        int last_index = -1;
        for (const char c: word) {
            const vector<int>& p = pos[c];
            const auto it = std::lower_bound(p.begin(), p.end(), last_index +1);
            if (it==p.end()) {m_[word] = false; return false;}
            last_index = *it;
        }
        m_[word] = true;
        return true;
    }
    
};



class Solution {//Indexing + binary search: map S to {char: [indices]} "acbca" -> pos = {'a':[0,4], 'b':[2], 'c':[1,3]}
public://Time: O(S) + O(W*L*Log(S))   Space: O(S)
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int>> pos;
        for (int i=0;i<S.length();++i)
            pos[S[i]].push_back(i);
        
        int ans = 0;
        for (const string& word : words)
            ans += isMatch(word, pos) ? 1 : 0;
        return ans;
    }
    
private:
    unordered_map<string, bool> m_;
    bool isMatch(const string& word, unordered_map<char, vector<int>>& pos){
        if (m_.count(word)) return m_[word];//previously checked
        int last_index = -1;
        for (const char c: word) {
            const vector<int>& p = pos[c];
            const auto it = std::lower_bound(p.begin(), p.end(), last_index +1);
            if (it==p.end()) {m_[word] = false; return false;}
            last_index = *it;
        }
        m_[word] = true;
        return true;
    }
    
};













