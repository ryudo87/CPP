//Greedy: Optimized brute force: for each starting index i, find the longest substring. Time: O(n) * O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int ans = 0;
        for (int i=0;i<n;++i) {
            vector<int> seen(128);
            int j=i;
            while(j<n && !seen[s[j]]) {
                seen[s[j]]++;++j;
            }
            ans = max(ans, j-i);
        }
        
        return ans;
    }
};


