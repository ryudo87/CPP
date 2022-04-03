
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"




class Solution {
public:
  int SubGen(vector<string> & output, string prefix, int n, int l, int r){
    //n: total number of parenthesis pairs
    //l: number of left parenthesis available
    //r: number of right parenthesis available
    //prefix: previously fixed string part
    //return number of strings added
    
    //First, determins the determination conditions
    int num = 0;
    if(l>r){//there are more left parenthsis left
      return 0;
    }
    if(prefix.size() == 2*n-1){//we are about to finish the string and add them to the output
      // only 1 slot available, no way there are still left parenthesis
      if(l!=0 || r!= 1) return 0;
      output.push_back(prefix+')');
      return 1;
    }
    
    //the string in prefix is valid according to the check l>r in before
    //l<=r in below, r must be greater than 0, or l=r=0
    if(l>0) //there are still left parenthesis available
      num += SubGen(output,prefix+'(',n,l-1,r);
    num += SubGen(output,prefix+')',n,l,r-1);
    return num;
  }
  
  vector<string> generateParenthesis(int n) {
      vector<string> output;
      string prefix;
      int num;
      num = SubGen(output,prefix,n,n,n);
      return output;
  }
};