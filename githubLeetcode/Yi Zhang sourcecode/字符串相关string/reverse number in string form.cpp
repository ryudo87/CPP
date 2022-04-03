#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

//1. Given a string which represents a number, return the reverse number in string form, e.g:
//"  200" -> "2"
//"1234"->"4321"
//"1009"->"9001"
//follow up: how would you design it? can it run in O(n)? memory management?
//test cases: (zero, negative numbers, trailing spaces and zeros, floats)

string reverseIntString(string s) {
  if (s.empty()) {
    return s;
  }
  string res;
  int i=s.size()-1;
  
  while (i>=0 && (s[i] == ' ' || s[i] == '0')) {
    --i;
  }
  
  while (i>=0) {
    if (isspace(s[i])) {
      break;
    }
    if (s[i] == '-' || s[i] == '+') {
      res.insert(0, 1, s[i]);
      break;
    }
    
    if (s[i]=='.') {
      if (res.empty()) {
        res.push_back('0');
      }
    }
    
    res.push_back(s[i]);
    --i;
  }
  
  if (res.empty()) {
    return "0";
  }
  return res;
}
int main()
{
  cout<<reverseIntString("  -200 ")<<endl;
  cout<<reverseIntString("-1.3200 ")<<endl;
  cout<<reverseIntString("  0")<<endl;
  cout<<reverseIntString("  +0.5  ")<<endl;
  cout<<reverseIntString("  -5.0 ")<<endl; // ??
  return 0;
}

