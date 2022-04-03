///my optimization on huahua
//
class Solution {//divide by operator recursively
    unordered_map<string, vector<int>> m_;
    
public:
    vector<int> diffWaysToCompute(string input) {
        if (m_.count(input)) return m_[input];
        
        vector<int> ans;
        for (int i=1;i<input.length();++i) {//i from 1??
            char op = input[i];
            //split input by an op
            if (op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);//substr from i+1 to end
                //Get solution for left/right sub-expressions
                const vector<int>& l = diffWaysToCompute(left);
                const vector<int>& r = diffWaysToCompute(right);
                
                //Combine solutions
                for (int a : l) {
                    for (int b : r) {
                        int res = 0;
                        switch(op) {
                            case '+': res = a+b; break;
                            case '-': res = a-b;break;
                            case '*': res = a*b;break;
                        }
                        ans.push_back(res);
                    }
                }
            }
        } //end iterate thru input
        
        //single number case
        if (ans.empty()) {
            ans.push_back(std::stoi(input));
        }
        m_[input] = ans;
        return ans;
    }//end of ways
};


///////////huahua solution/////////////////
namespace huahua {
    int addF(int a, int b) { return a+b; }
    int minusF(int a, int b) { return a-b; }
    int plusF(int a, int b) { return a*b; }
}
class Solution {//divide by operator recursively
    unordered_map<string, vector<int>> m_;
    
public:
    vector<int> diffWaysToCompute(string input) {
        return ways(input);
    }
    
    vector<int> ways(string input) {
        if (m_.count(input)) return m_[input];
        
        vector<int> ans;
        for (int i=0;i<input.length();++i) {//i from 1??
            char op = input[i];
            //split input by an op
            if (op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);//substr from i+1 to end
                //Get solution for left/right sub-expressions
                const vector<int>& l = ways(left);
                const vector<int>& r = ways(right);
                
                std::function<int(int, int)> f;
                switch(op) {
                    case '+': f=huahua::addF;break;
                    case '-': f=huahua::minusF;break;
                    case '*': f=huahua::plusF;break;
                }
                
                //Combine solutions
                for (int a : l) {
                    for (int b : r) {
                        ans.push_back(f(a, b));
                    }
                }
            }
        }
        //after iterate thru input
        //single number case
        if (ans.empty()) {
            ans.push_back(std::stoi(input));
        }
        m_[input] = ans;
        return ans;
    }//end of ways
};
