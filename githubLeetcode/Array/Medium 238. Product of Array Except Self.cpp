//https://wdxtub.com/interview/14520604918412.html
//当前节点的解，既和左边的元素有关，又与右边的元素有关，两者相互独立，可以用双向DP。左遍历DP计算积累到目前为止的乘积，右遍历DP计算从目前开始到最后的乘积。
//两次遍历，时间复杂度 O(n)，空间复杂度 O(n)，空间可以优化至 O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i=1;i<n;++i) {
            res[i] = res[i-1] * nums[i-1];
            cout<<"res["<<i<< "]=" <<res[i]<<endl;
        }
        
        int prod = nums[n-1];
        for (int i=n-2;i>=0;--i) {
            res[i] = res[i] * prod;
            prod *= nums[i];
        }
        
        return res;
    }
};
