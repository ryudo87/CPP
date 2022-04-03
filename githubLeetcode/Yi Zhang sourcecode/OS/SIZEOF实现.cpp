
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
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

#define __SIZEOF(x) \
({ \
struct { \
typeof(x) y; \
char c[0]; \
} __attribute__((__packed__)) s; \
(size_t) (&((typeof(s)*) 0)->c); \
})

#define mySize(w)
int main()
{



	int a;
	//typeof(int) x;
	//typeof(a) y;

	//cout<<my_sizeof(a)<<endl;
	cout<<__SIZEOF(int)<<endl;
	cout<<__SIZEOF(a)<<endl;
	cout<<sizeof(a)<<endl;
	return 0;
}





