class Solution {//first two elements can be chosen arbitrarily and at most 10*10 pairs(2^31 is 10 len string)
    //3rd element must be sum of previous two elements
    //Time: O(10*10*n)  Space: O(n)
public:
    vector<int> splitIntoFibonacci(string s) {//DFS
        const int n = s.length();
        vector<int> nums;
        function<bool(int)> dfs = [&](int pos) {
            if (pos == n) return nums.size()>=3;
            int max_len = s[pos]=='0' ? 1:10; // cannot have leading 0s
            long num = 0;
            for (int i=pos;i<min(pos+max_len, n); ++i) {
                num = num*10 + (s[i]-'0');
                if (num > INT_MAX) break;
                if (nums.size() >= 2) {
                    long sum = nums.rbegin()[0];
                    sum+=nums.rbegin()[1];
                    if (num > sum) return false;
                    else if (num < sum) continue;
                }
                //num must == sum
                nums.push_back(num);
                if (dfs(i+1)) return true;
                nums.pop_back();
            }
            
            return false;
        };
        
        
        dfs(0);
        return nums;
    }
};
