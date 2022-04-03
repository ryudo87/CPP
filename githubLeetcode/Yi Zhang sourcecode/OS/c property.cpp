#include "stdafx.h"
#include <cstdio>
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



#define a(x) #x//#生成字符串
#define b(x) "ab"##x
#define c(x) "ab"#x
#define SEC (unsigned long)60*60*24*36500
#define un_SEC 60*60*24*36500UL
#define signSEC 60*60*24*36500
//#error wrong  
//produce compiler-time error msg 
struct taxonomy {
     int kingdom : 12;
     int phylum : 6;
     int genus : 2;
};
// integer members to be stored into memory spaces smaller than
//the compiler would ordinarily allow. These space-saving structure
//members are called bit fields, and their width in bits can be explicitly declared.


void main(void)
{	 





	int i=3; 
	int j; 
	j = sizeof(++i+ ++i); 
	printf("i=%d j=%d\n", i ,j); 
//sizeof 操作符给出其操作数需要占用的
  //空间大小，它是在编译时就可确定的，
  //所以其操作数即使是一个表达式，
  //也不需要在运行时进行计算.
  //( ++i + ++ i )是不会执行的，
  //所以i 的值还是3 





//考查逗号表达式 
	//考查逗号表达式,逗号表达式的优先级是很低的，
	//比赋值(=)的优先级低. 逗号表达式的值就是最后一个元素的值 
 int a, b,c, d; 
  a=3; 
  b=5; 
  c=a,b; 
  d=(a,b); 
  printf("c=%d\n" ,c); 
  printf("d=%d\n" ,d); 

	cout<<a(bcd)<<endl;
	cout<<b("123")<<endl;
	//cout<<b(12)<<endl;
	cout<<c(12)<<endl;
	cout<<c("12")<<endl;
	cout<<SEC<<endl;
	cout<<un_SEC<<endl;
	cout<<signSEC<<endl;

  /*int a[] = {1,2,3,4,5,6,7}; 
  int (**b)=(int**)&a;
  int *ptr2 = (int*)(&a+1); 
  int *ptr = (int*)(b+1); 
  printf("%d %d %d" , *(a+1), *(ptr-1),*(ptr2-1) ); */


//a的类型是一个整型数组,它有5个成员 
//&a的类型是一个整型数组的指针 
//所以&a + 1指向的地方等同于 a[6] 
//所以*(a+1) 等同于a[1] 
//ptr等同 a[6], ptr-1就等同与a[5] 



}
