//Brute force: for each * , 1) ignore it 2) change to (  3) change to )  Time:O(n*3^k)  k is number of *


//DP:  Case1: LLLRRR  case2: LRLR  Time: O(N^3) Space O(N^2)
class Solution {
public:
    bool checkValidString(string s) {
        int l = s.length();
        vector<vector<int>> m_ (l, vector<int>(l, -1));
        return isValid(s, 0, l-1, m_);
    }
    
    bool isValid(const string& s, int i, int j, vector<vector<int>>& m_) {
        if (i>j) return true;
        if (m_[i][j] >= 0) return m_[i][j]; // s[i..j]already checked before
        if (i==j) {
            m_[i][j] = (s[i] == '*');
            return m_[i][j];
        }
        
        //case: L....R
        if ( (s[i] == '(' || s[i] == '*')
            && (s[j] == ')' || s[j] == '*')
            && isValid(s, i+1, j-1, m_)) {
            m_[i][j] = 1;
            return true;
        }
        //case: L..RL...R
        for (int p=i;p<j;++p) {
            if (isValid(s, i, p, m_) && isValid(s, p+1, j, m_)) {
                m_[i][j] = 1;
                return true;
            }
        }
        
        m_[i][j] = 0;
        return false;
    }
};


//Counting: min_op , max_op track min/max possible open "("     success match: max_op must >=0 ,  if min_op<0, reset it to 0.  check min_op == 0
//Time: O(n)  Space O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int min_op = 0;//min unmatched (
        int max_op = 0;//max potential (
        
        for (char c : s) {
            if ('(' == c) ++min_op;
            else --min_op;// case * or )
            if (')' != c) ++max_op;
            else --max_op;// case )
            if (max_op < 0) return false;
            min_op = max(0, min_op);
        }
        
        return (0 == min_op);
    }
};




