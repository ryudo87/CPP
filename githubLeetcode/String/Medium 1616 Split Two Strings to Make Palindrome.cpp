class Solution {//Greedy:try to match prefix of A and suffix of B as much as possible
public: //And then check whether middle part of A or B is palindrome
    bool checkPalindromeFormation(string a, string b) {
        auto isPalindrome = [](const string& s, int i, int j) {
            while(i<j&&s[i] == s[j]) ++i, --j;
            return i>=j;
        };
        auto checkPalindromeImp = [&isPalindrome] (const string& a, const string& b) {
            int i=0, j=a.length()-1;
            while (i<a.length() && a[i] == b[j]) {++i, --j;}
            return isPalindrome(a, i, j) || isPalindrome(b, i, j);
        };
        return checkPalindromeImp(a, b) || checkPalindromeImp(b, a);
    }
};

class Solution {//Greedy:try to match prefix of A and suffix of B as much as possible
public: //And then check whether middle part of A or B is palindrome
    auto isPalindrome(const string& s, int i, int j) {
        while(i<j&&s[i] == s[j]) ++i, --j;
        return i>=j;
    }
    bool checkPalindromeFormation(string a, string b) {
        auto checkPalindromeImp = [=] (const string& a, const string& b) {
            int i=0, j=a.length()-1;
            while (i<a.length() && a[i] == b[j]) {++i, --j;}
            return isPalindrome(a, i, j) || isPalindrome(b, i, j);
        };
        return checkPalindromeImp(a, b) || checkPalindromeImp(b, a);
    }
};
