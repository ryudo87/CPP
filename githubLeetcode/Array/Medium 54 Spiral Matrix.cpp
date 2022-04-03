// 重要的是要确定上下左右四条边的位置，那么初始化的时候，上边up就是0，下边down就是m-1，左边left是0，右边right是n-1。
// 然后我们进行while循环，1) 先遍历上边，将所有元素加入结果res，
// 2)然后上边下移一位，如果此时上边大于下边，说明此时已经遍历完成了，直接 break。同理对于下边，左边，右边，依次进行相对应的操作

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        
        while(true) {
            for (int j=left;j<=right;++j) res.push_back(matrix[up][j]);//1) 先遍历上边
            if (++up>down) break;//2)然后上边下移一位，如果此时上边大于下边，说明此时已经遍历完成了
            for (int i=up;i<=down;++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j=right;j>=left;--j) res.push_back(matrix[down][j]);
            if (--down<up) break;
            for (int i=down;i>=up;--i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
