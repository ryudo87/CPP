class Solution {//Brute force  Time O(n^2)  Space O(1)
public://Prefix-sum Time O(n)  Space O(1)
    //Shift: S[i] = (S[i] - 'a' + shift) %26 + 'a' = (S[i] - 'a' + shift%26) %26 + 'a'
    string shiftingLetters(string s, vector<int>& shifts) {
        int c=0;
        for (int i=shifts.size()-1;i>=0;--i) {
            c+=(shifts[i]%26);
            s[i] = (s[i]-'a'+c)%26 + 'a';
        }
        return s;
    }
};
