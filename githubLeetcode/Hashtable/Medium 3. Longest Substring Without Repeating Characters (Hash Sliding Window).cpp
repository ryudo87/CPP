//Yi Zhang Slide Window:  Window (i, j) with unique char
//1. user hashtable to store last index of each char 2.keep track valid starting point: when a match, update starting point to current one
//Time O(n) Space (O(hashtable))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int ans = 0;
        unordered_map<int, int> idxMap;
        for (int i=0, j=0;j<n;++j) {
            if (idxMap.count(s[j]) != 0) { //s[j] was visited
                
                std::cout<<s[j]<<" was visited, "<<i<<" -> "<<max(i, idxMap[s[j]] + 1)<<std::endl;
                //s[j] is the char on right, update left border (move i to last idx of s[j] + 1)
                //!!!i  can be smaller than idxMap[s[j]] + 1, so must use max(i, idxMap[s[j]] + 1)
                i = max(i, idxMap[s[j]] + 1);
            }
            idxMap[s[j]] = j; //update s[j] last idx
            ans = max(ans, j-i+1);//update windows size
        }
        
        return ans;
    }
};


//HuaHua Slide Window:  Window (i, j) with unique char
//1. user hashtable to store last index of each char 2.keep track valid starting point: when a match, update starting point to current one
//Time O(n) Space (O(hashtable))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int ans = 0;
        vector<int> idx(128, -1);
        for (int i=0, j=0;j<n;++j) {
            i = max(i,  idx[s[j]]+1);  //s[j] is the char
            ans = max(ans, j-i+1);//update windows size
            idx[s[j]] = j;
        }
        
        return ans;
    }
};
