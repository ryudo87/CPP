
class Solution {//"ab" pattern, b is larger than a. The value changes from a+b to b-a
public://Sum all symbols up, when encounter "ab pattern", minus 2*a .  Time O(n) space O(1)
    int romanToInt(string s) {
        unordered_map<char, int> m{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
            , {'C', 100}, {'D', 500}, {'M', 1000}
        };
        char p = 0; int ans = 0;
        for (char c:s) {
            ans += m[c];
            if (p && m[c] > m[p])
                ans -= 2*m[p];
            p = c;
        }
        return ans;
    }
};

http://www.cnblogs.com/TenosDoIt/p/3793503.html
class Solution {
public:
  int romanToInt(string s) {
    int map[26];
    map['I'-'A'] = 1; map['V'-'A'] = 5; map['X'-'A'] = 10; map['L'-'A'] = 50;
    map['C'-'A'] = 100; map['D'-'A'] = 500; map['M'-'A'] = 1000;
    int res = 0, n = s.size();
    s.push_back(s[n-1]);
    for(int i = 0; i < n; i++)
    {
      if(map[s[i]-'A'] >= map[s[i+1]-'A'])
        res += map[s[i]-'A'];
      else res -= map[s[i]-'A'];
    }
    return res;
  }
};
