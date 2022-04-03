/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {//at most one numer can occur odd times, other numbers must occur even times
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);//10 size each 0 value
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (nullptr == node) return 0;
            ++counts[node->val];
            int c=0;
            if (!node->left && !node->right) {//leaf node case
                int odds = 0;
                for (int i=1;i<=9;++i) {
                    if (counts[i] % 2 != 0) ++odds;
                }
                if (odds<=1) c=1;//cannot return here, need to --counts[node->val]
            }
            int l=dfs(node->left);
            int r=dfs(node->right);
            --counts[node->val];//!!backtracking
            return c+l+r;
        };
        
        return dfs(root);
    }
};


class Solution {//at most one numer can occur odd times, other numbers must occur even times
public:
    int dfs(TreeNode* node, vector<int>& counts) {
        if (nullptr == node) return 0;
        ++counts[node->val];
        int c=0;
        if (!node->left && !node->right) {//leaf node case
            int odds = 0;
            for (int i=1;i<=9;++i) {
                if (counts[i] % 2 != 0) ++odds;
            }
            if (odds<=1) c=1;//cannot return here, need to --counts[node->val]
        }
        int l=dfs(node->left, counts);
        int r=dfs(node->right, counts);
        --counts[node->val];//!!backtracking
        return c+l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);//10 size each 0 value
        return dfs(root, counts);
    }
};



class Solution {//at most one numer can occur odd times, other numbers must occur even times
    //use binary (int s) to represent state of odd/even counts (0:even / 1:odd)
    //Flip the bit: state ^= (1<<n)
public:
    int pseudoPalindromicPaths (TreeNode* root, int s = 0) {
        if (!root) return 0;
        s ^= (1<<root->val);
        int ans = 0;
        if (!root->left && !root->right)
            ans += (__builtin_popcount(s) <= 1);//count number of bits
        //pass s by copy, no need to restore state(no backtracking)
        ans += pseudoPalindromicPaths(root->left, s);
        ans += pseudoPalindromicPaths(root->right, s);
        return ans;
    }
};
