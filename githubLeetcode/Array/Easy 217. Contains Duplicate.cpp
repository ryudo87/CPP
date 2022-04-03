class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for (int i:nums) {
            if (myset.find(i) != myset.end()) return true;
            myset.insert(i);
        }
        return false;
    }
};
