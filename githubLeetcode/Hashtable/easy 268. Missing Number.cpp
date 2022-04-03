class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }
        
        for (int i=0;i<=nums.size();++i) {
            if (numSet.count(i) == 0) return i;
        }
        
        return -1;
    }
};
