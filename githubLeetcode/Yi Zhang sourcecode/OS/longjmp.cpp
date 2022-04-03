#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <deque>
#include <memory>
#include <ctime>
#include <typeinfo>
#include <hash_set>
#include "tree.h"
using namespace std;
#include <setjmp.h> 

struct AF
{	int a;
	int b;
};

static jmp_buf buf; 
void main()  
{ 
	AF af[]={{1,2},{3,4}};
  volatile int b; 
  b =3; 
  
  int ret=setjmp(buf);
  if(ret!=0)  
  { 
	  cout<<"ret of setjmp:"<<ret<<endl;
	  printf("%d ", b);  
	  exit(0); 
  } 
  b=5; 
  longjmp(buf , -1); 
}  