#include "all.h"

//Evaluate Reverse Polish Notation Total Accepted:
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

bool isOp(string str) {
  return str=="+"||str=="-"||str=="*"||str=="/";
}

int calculate(int num1, int num2, string op) {
  // divide by 0??
  if (op =="+") {
    return num1+num2;
  }
  if (op =="-") {
    return num1-num2;
  }
  if (op =="*") {
    return num1*num2;
  }
  if (op =="/") {
    return num1/num2;
  }
  throw "op";
}
int evalRPN(vector<string> &tokens) {
  stack<int> st;
  for (size_t i=0; i<tokens.size(); ++i) {
    if (isOp(tokens[i])) {
      int a=st.top();
      st.pop();
      int b=st.top();
      st.pop();
      
      int res = calculate(b, a,tokens[i]);
      st.push(res);
    } else {
      st.push(atoi(tokens[i].c_str()));
    }
  }
  
  return st.top();
}



//negative operand,
//invalid input
//算逆波兰表达式。
double get_reverse_Polish_notation(string expr)
{
	double num=0, op1,op2;unsigned i=0;
	stack<double> op;
	while(i<expr.length())
	{
		if(expr[i]==' '){
			if(num!=0){
				op.push(num);
				num=0;
			}
		}

		else if(isdigit(expr[i])){
			num=num*10+expr[i]-'0';
		}

		else{
			op2=op.top();op.pop();
			op1=op.top();op.pop();
			switch(expr[i]){
						case '+':{op1+=op2; break;}
						case '-':{op1-=op2; break;}
						case '*':{op1*=op2; break;}
						case '/':{op1/=op2; break;}
						default:{cerr<<"invalid input"<<endl;exit(1);}
			}
			op.push(op1);
		}
		i++;
	}

	return op.top();
}

int main()
{
	string expr="1 2 + 3 4 * / ";
	cout<<expr<<"="<<get_reverse_Polish_notation(expr)<<endl;
	return 0;
}

