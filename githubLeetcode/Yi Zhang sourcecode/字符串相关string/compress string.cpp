#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include <sstream>
#include <cmath>
#include <iterator>
#include <cmath>

using namespace std;

//extreme cases
//1) ""
//2) "a"
//3) "aaaa"
//4) "1aa2"
//5) "11122"
//6) "abc123"

map<char, char> charMap;

string compress(string s) {
  string res;
  int cnt = 1;
  for(int i=0;i<s.size();++i) {
    if (i == s.size()-1 || s[i] != s[i+1]) {
      if (cnt>1) {
        res+=to_string(cnt);
        cnt=1;
      }
      res+=charMap[s[i]];
    } else {
      ++cnt;
    }
  }
  
  return res;
}


int main() {
  charMap['a'] = 'a';
  charMap['1'] = '!';
  cout<<compress("aaaaaaaaaaaa1")<<endl;
  cout<<compress("1a")<<endl;
  cout<<compress("1111")<<endl;
  
  return 0;
}

// run-length encoding
// 000000011100010000011001
// 7 zeros, 3 ones, 3 zeros, 1 one, 5 zeros, ...

// input: lowercase letters and numbers

// abc123



//   aaaaaaaaaa => 10a


//   map: 0-9 =>  ), !, @, #, $
//        a-z =>  a-z




