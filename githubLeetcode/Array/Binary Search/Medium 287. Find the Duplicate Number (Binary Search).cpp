//二分查找。初始时查找区间为整个数组，取数组的中间位的index，遍历一遍区间，查看小于等于index的数字个数，如果个数大于index，说明重复的数字在1-mid之间，反之在mid+1到n区间。继续二分查找。本解法时间复杂度为nlogn

// 那我们也就只能考虑用二分搜索法了，我们在区间 [1, n] 中搜索，首先求出中点 mid，然后遍历整个数组，统计所有小于等于 mid 的数的个数，如果个数小于等于 mid，
// 则说明重复值在 [mid+1, n] 之间，反之，重复值应在 [1, mid-1] 之间，然后依次类推，直到搜索完成，此时的 low 就是我们要求的重复值
class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        const int n = nums.size()-1;
        int left = 1, right = n;
        while (left<right) {
            int mid = left + (right-left)/2;
            int cnt = 0;
            for (int num:nums) {//然后遍历整个数组，
                if (num <= mid) {//统计所有小于等于 mid 的数的个数
                    ++cnt;
                }
            }
            if (cnt<=mid){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
