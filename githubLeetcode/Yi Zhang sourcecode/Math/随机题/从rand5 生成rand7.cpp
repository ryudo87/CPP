#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <list>
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
using namespace std;
#define M 4
#define N 6
typedef unsigned char byte;

int rand5()
{
	return rand()%5;
}
int rand7()
{
	while(true){
		int num=5*rand5()+rand5();
		if(num<21) return (num%7);
	}
}
void main(void)   
{
	for(int i=0;i<100;i++)
		cout<<rand7()<<endl;
}