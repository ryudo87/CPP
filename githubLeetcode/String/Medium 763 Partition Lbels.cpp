//Brute Force Time: O(n^2) Space: O(1)
class Solution {//Hashtable(or vector<int>) Time: O(n) Space O()
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_index(128, 0);
        for (int i=0;i<S.size();++i)
            last_index[S[i]] = i;
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i=0;i<S.size();++i) {
            end = max(end, last_index[S[i]]);
            if (i==end) {
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};


