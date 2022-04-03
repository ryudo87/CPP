//if s[l]!=s[r]:
// check(s[l+1..r])  and check(s[l..r-1])
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
            }
            else {
                ++l;--r;
            }
        }
        
        return true;
    }
    
    bool isPalindrome(const string& s, int l, int r) {
        while(l<r) {
            if (s[l] != s[r]) return false;
            ++l;--r;
        }
        return true;
    }
};
