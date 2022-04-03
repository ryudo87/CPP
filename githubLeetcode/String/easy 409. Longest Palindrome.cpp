//Brute force: try all permutation, Time (O(n!)) factorial

class Solution {//Greedy: Time O(n)n , Space O(128) = O(1)
    //1.Count frequency of each character
    //2.Build from center, pick a pair (same char), put one at front and one at end.
    //3. if a single left, put it in the middle
public:
    int longestPalindrome(string s) {
        vector<int> freqTable(128, 0); //A-Z是65-90。 a-z是97-122
        int ans = 0;
        for (const char c : s) ++freqTable[c];
        
        int odd = 0;
        for (const int freq : freqTable) {
            ans += (freq % 2 == 0) ? freq : freq -1;
            if (freq%2 != 0) odd = 1;
        }
        return (ans += odd);
    }
};
//2019 solution
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int maxlen = 0;
        for (auto c : s) {
            if (freq.find(c) == freq.end()) {
                freq[c] = 1;
            } else {
                freq[c] ++;
                if (freq[c]%2 == 0) {
                    maxlen += 2;
                }
            }
        }
        
        if (maxlen < s.size()) {
            maxlen ++;
        }
        return maxlen;
    }
};
