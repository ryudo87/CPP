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

#include <stdarg.h> 
int ripple (int n, ...) 
{ 
  int i , j,k=0; 
  va_list p; 
  va_start( p , n);  
  for (j=0; j <n; ++j) 
  { 
	  i = va_arg( p , int); 
	  for (; i; i &=i-1 ) 
		++k; 
  } 
  return k; 
} 

void main()  
{ 
  int num; 
  num = ripple (2, 5,7); 
  printf( " %d" , num); 

}  