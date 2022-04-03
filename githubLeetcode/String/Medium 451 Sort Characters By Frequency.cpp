class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (char c:s) ++f[c];
        sort(s.begin(), s.end(), [&f](char a, char b) {
            return f[a]>f[b] || (f[a]==f[b] && a>b);
        });
        return s;
    }
};
//2019 solution
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char2freq;
        for (auto c : s) {
            char2freq[c] ++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p:char2freq) {
            pq.push({p.second, p.first});
        }
        
        string res;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            for (int i=0;i<p.first;++i) {
                res += p.second;
            }
        }
        
        
        return res;
    }
};
