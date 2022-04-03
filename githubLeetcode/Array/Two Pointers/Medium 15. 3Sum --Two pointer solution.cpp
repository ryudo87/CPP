//Two Pointers
// 1 sort nums  2 enumberate nums[i]  3 use two pointers to find all pairs of <j, k> such that  i<j<k
// Time O(n^2), space O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i=0;i<n;++i) {
            if (i>0 && nums[i] == nums[i-1]) continue; //de-dup
            int j=i+1, k=n-1;
            
            while (j<k) {
                if (nums[i] + nums[j] + nums[k] > 0) --k;
                else if (nums[i] + nums[j] + nums[k] < 0) ++j;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j] == nums[j+1]) ++j;
                    while(j<k && nums[k] == nums[k-1]) --k;
                    ++j, --k;
                }
            }
        }
        
        return ans;
    }
};
