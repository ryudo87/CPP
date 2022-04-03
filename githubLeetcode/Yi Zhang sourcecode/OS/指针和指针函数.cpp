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

int fun(int a)
{	
	static int stav;
	return 1;
}
void main(void){
	int conInt=3;;
	int const* con_a=&conInt;
	 int const* con_b const;

	int * const conP ;
	//*conP=5;

	int b[10]={0};
	int (*a)[10]=&b;
	
	//a=b;
	int (*ff[10])(int);
	ff[0]=fun;
	ff[2]=fun;
	ff[3]=fun;
}