//http://39.107.221.112/article/339075
// 这题我们也可以用二分查找法来做，我们由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，
//如果目标数在比该行的尾元素大 也就是比该行所有都大，smaller_than_mid_count=该行元素的个数，
//如果目标数比该行首元素小 也就是比该行所有都小，smaller_than_mid_count==0
//我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，
//本解法的整体时间复杂度为O(nlgn*lgX)，其中X为最大值和最小值的差值 X = matrix.back().back() - matrix.front().front()

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix.front().front(), right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                //所以我们要在每一行都查找一下mid，我们使用upper_bound，这个函数是查找第一个大于目标数的元素
                //如果目标数在比该行的尾元素大 也就是比该行所有都大，smaller_than_mid_count=该行元素的个数，
                //如果目标数比该行首元素小 也就是比该行所有都小，smaller_than_mid_count==0
                int smaller_than_mid_count = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                cnt += smaller_than_mid_count;
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

// 上面的解法还可以进一步优化到O(nlgX)，其中X为最大值和最小值的差值，我们并不用对每一行都做二分搜索法，
//我们注意到每列也是有序的，我们可以利用这个性质，从数组的左下角开始查找，
//如果比目标值小，我们就向右移一位，而且我们知道当前列的当前位置的上面所有的数字都小于目标值，那么cnt += i+1，
//反之则向上移一位，这样我们也能算出cnt的值。

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, smaller_than_target_cnt = 0;
        while (i >= 0 && j < n) {
            //如果比目标值小，我们就向右移一位，而且我们知道当前列的当前位置的上面所有的数字都小于目标值，那么cnt += i+1，
            //反之则向上移一位，这样我们也能算出smaller_than_target_cnt的值。
            if (matrix[i][j] <= target) {
                smaller_than_target_cnt += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return smaller_than_target_cnt;
    }
};
