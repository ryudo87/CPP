// 第一种解法，这种解法的思路路是，对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋值为其相反数，如果已经是负数了，就不变了，那么最后我们只要把留下的整数对应的位置加入结果res中即可


// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> res;
//         for (int i=0;i<n;++i) {
//             int idx = abs(nums[i]) - 1;
//             nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
//         }

//         for (int i=0;i<n;++i) {
//             if (nums[i] > 0) {
//                 res.push_back(i+1);
//             }
//         }

//         return res;
//     }
// };

//第二种方法是将nums[i]置换到其对应的位置nums[nums[i]-1]上去，比如对于没有缺失项的正确的顺序应该是[1, 2, 3, 4, 5, 6, 7, 8]，而我们现在却是[4,3,2,7,8,2,3,1]，我们需要把数字移动到正确的位置上去，比如第一个4就应该和7先交换个位置，以此类推，最后得到的顺序应该是[1, 2, 3, 4, 3, 2, 7, 8]，我们最后在对应位置检验，如果nums[i]和i+1不等，那么我们将i+1存入结果res中即可

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                continue;
            }
            ++i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};


