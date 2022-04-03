#include "all.h"

//Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


bool isValid(string s) {
	stack<char> st;char c;
	for(int i=0;i<s.size();++i){
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			st.push(s[i]);
			continue;
		}
		
    if(st.empty()) return false;
    c=st.top();
    st.pop();
    if(s[i]==')'){
      if(c!='('){
        return false;
      }
    }
    else if(s[i]==']'){
      if(c!='['){
        return false;
      }
    }
    else if(s[i]=='}'){
      if(c!='{'){
        return false;
      }
    }

	}

	if(st.empty()) return true;
	return false;
}
int main()
{
	int arr[]={3, 7, 4, 1, 2, 6, 5};
	//printf( "Total %d combinations.\n", boogie(5) );
	return 0;
}
