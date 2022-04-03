
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string.h>
#include <stddef.h>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <memory>
using namespace std;
#define Max 100


struct mystname
{	
	char c;
	int a;
};

#define __SIZEOF(x) \
({ \
	struct { \
		typeof(x) y; \
		char c[0]; \
	   } __attribute__((__packed__)) s; \
(size_t) (&((typeof(s)*) 0)->c); \
})

#define mysizeof(var) (size_t)((char*)(&var+1)-(char*)&var)
#define mysizeof_type(type) (size_t)((type *)(0)+1)

#define myoffsetof(struct_name,field) \
(size_t)&(((struct_name *)0)->field)

int compare_and_swap (int* reg, int oldval, int newval) 
{
  int old_reg_val = *reg;
  if (old_reg_val == oldval) 
     *reg = newval;
  return old_reg_val;
}

//
#define LOCKED 1
 int TestAndSet(int* lockPtr) {
     int oldValue;
     oldValue = SwapAtomic(lockPtr, LOCKED);
     return oldValue == LOCKED;
 }

 //´óÎ²¶Ë×ª»»
 uint32_t endian_convert(uint32_t bvalue)
{
   uint32_t lval;
  lval = ((bvalue >>24)&0xff) |
                    ((bvalue <<8)&0xff0000) |
                    ((bvalue >>8)&0xff00) |
                    ((bvalue <<24)&0xff000000);
  return lval;
}
int main()
{

	int a;
	typeof(int) x;
	typeof(a) y;

	cout<<my_sizeof(a)<<endl;
	cout<<__SIZEOF(int)<<endl;
	cout<<__SIZEOF(a)<<endl;
	cout<<sizeof(a)<<endl;
	return 0;
}





