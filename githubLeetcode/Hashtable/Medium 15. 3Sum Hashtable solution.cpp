//Hashtable:  just need to enumerate all pairs of <nums[i], nums[j]>, check whether (0-nums[i]-nums[j]) exist
// <-3 1>, we check whether 2 exists or not. we also need to count
// How to remove duplicates: 1) make sure nums[i] <= nums[j] <= nums[k]  2) for each position, only use first occurrence of each num (skip num[i] if nums[i] == nums[i-1])

// Time : O(n^2) Space O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        
        unordered_map<int, int> freqMap;
        for (int x:nums) ++freqMap[x];
        
        for (int i=0;i<nums.size();++i) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            
            for (int j=i+1;j<nums.size();++j) {
                if (j-1 != i && nums[j] == nums[j-1]) continue;
                
                int t = 0 - nums[i] - nums[j];
                if (t<nums[j]) continue;
                if (freqMap.count(t) == 0) continue;
                
                //make sure we have enough count
                if (freqMap[t] >= 1 + (nums[i] == t ? 1 : 0) + (nums[j] == t ? 1 : 0))
                    ans.push_back({nums[i], nums[j], t});
            }
        }
        
        return ans;
        
    }
};
