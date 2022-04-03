class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> l(26, 0);//can use unordered_map
        for (const char ch : licensePlate) {
            if (isalpha(ch)) ++l[tolower(ch)-'a'];
        }
        string ans;
        int min_l = INT_MAX;
        for (const string& word : words) {
            if (word.length() >= min_l) continue;
            if (!matches(l,word)) continue;
            min_l = word.length();
            ans = word;
        }
        
        return ans;
    }
    
    bool matches(const vector<int>& l, const string& word) {
        vector<int> c(26, 0);
        for (const char ch : word) {
            ++c[tolower(ch) - 'a'];
        }
        for (int i=0;i<26;++i) {
            if (c[i] < l[i]) return false;
        }
        
        return true;
    }
};
