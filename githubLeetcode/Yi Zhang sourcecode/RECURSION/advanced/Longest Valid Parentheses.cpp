#include "all.h"

//Longest Valid Parentheses
//Given a string containing just the characters '(' and ')',
//find the length of the longest valid (well-formed) parentheses substring.

//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//"()(()" == 2



//—————————-用stack的做法———————————–
//stack里面装的一直是“还没配好对的那些可怜的括号的index”
//是’(‘的时候push
//   是’)’的时候，说明可能配对了；看stack top是不是左括号，不是的话，push当前右括号
//是的话，pop那个配对的左括号，然后update res：i和top的（最后一个配不成对的）index相减，就是i属于的这一段的当前最长。如果一pop就整个栈空了，说明前面全配好对了，那res就是最大=i+1







//Method 1
// 只是利用 stack 记住开括号的下标，这是不够的，因为无法处理这
//种情况："()()(())".每次看到关括号，只能知道区配的开括号的位置，但这不一定是
//最长距离。
//
//用数组保存之前的结果，就是因为要处理以上这样的情况。 stack 只能告诉你区配关
//括号的起始位置。



int longestValidParentheses(string s) {
	int sz=s.size();
	int *dp=new int[sz];
	for(int i=0;i<sz;++i){
		dp[i]=-1;
	}
	stack<int> st;
	int curmax=0;

	for(int i=0;i<sz;++i)
	{
		char c=s[i];
		if('('==c){
			st.push(i);
		}
		else{
			if(!st.empty()){
				int m=st.top();st.pop();
				if(m>0 && dp[m-1]!=-1){
					dp[i]=min(dp[m-1],m);
				}
				else
					dp[i]=m;

				int len=i-dp[i]+1;
				if(len>curmax)
				{
					curmax=len;
				}

			}
		}
	}

	return curmax;
}

//Method2 扫描2次
//http://yewenxing.wordpress.com/2012/03/11/longest-valid-parentheses/

//int longestValidParentheses(string s) {

//    int n = s.length();
//    int maxl = 0;
//    int count = 0;
//    int len = 0;
//    for(int i = 0;i < n;i++){
//        if(s[i] == '('){
//            count++;
//            len++;
//        }
//        if(s[i] == ')') {
//            count--;
//            len++;
//        }
//        if(count == 0 && len > maxl){// one valid substring found
//            maxl = len;
//        }
//        else if(count < 0){//invalid pre-fix
//            len = 0;
//            count = 0;
//        }
//    }
//    count = 0;
//    len = 0;
//    for(int i = n-1;i >= 0;i--){
//        if(s[i] == ')'){
//            count++;
//            len++;
//        }
//        if(s[i] == '(') {
//            count--;
//            len++;
//        }
//        if(count == 0 && len > maxl){// one valid substring found
//            maxl = len;
//        }
//        else if(count < 0){//invalid pre-fix
//            len = 0;
//            count = 0;
//        }
//    }
//    return maxl;
//}




//Method 3
//http://blog.theliuy.com/2012/longest-valid-parentheses/


//int longestValidParentheses(string s) {
//
//        int s_size = s.size();
//        if (2 > s_size)
//            return 0;
//
//        int start = s_size + 1;
//        int end;
//        int max_length = 0;
//        int curr_length = 0;
//        stack<int> st;
//        for (end = 0; end < s_size; ++end) {
//            // Meet a (
//            if ('(' == s[end]) {
//                st.push(end);
//                continue;
//            }
//
//            // Meet a )
//            if (st.empty()) {
//                start = s_size + 1;
//            } else {
//                start = min(st.top(), start);
//                st.pop();
//
//                if (st.empty()) {
//                    curr_length = end - start + 1;
//                } else {
//                    curr_length = end - st.top();
//                }
//                max_length = max(max_length, curr_length);
//            }
//        }
//
//        return max_length;
//    }




int main()
{
	cout<<longestValidParentheses("(()())")<<endl;
	cout<<longestValidParentheses("()(()")<<endl;
	return 0;
}
