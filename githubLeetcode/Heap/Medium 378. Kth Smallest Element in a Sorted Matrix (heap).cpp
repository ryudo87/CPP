http://39.107.221.112/article/339075
// 这道题的难点在于数组并不是蛇形有序的，意思是当前行的最后一个元素并不一定会小于下一行的首元素，所以我们并不能直接定位第K小的元素，所以只能另辟蹊径。先来看一种利用堆的方法，我们使用一个最大堆，然后遍历数组每一个元素，将其加入堆，根据最大堆的性质，大的元素会排到最前面，然后我们看当前堆中的元素个数是否大于k，大于的话就将首元素去掉

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // what if k > n*n ??
        priority_queue<int> q;
        for (auto v : matrix) {
            for (auto i : v) {
                q.push(i);
                if (q.size()>k) {
                    q.pop();
                }
            }
        }
        
        return q.top();
    }
};
