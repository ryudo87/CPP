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



#define a(x) #x//#�����ַ���
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
//sizeof �������������������Ҫռ�õ�
  //�ռ��С�������ڱ���ʱ�Ϳ�ȷ���ģ�
  //�������������ʹ��һ�����ʽ��
  //Ҳ����Ҫ������ʱ���м���.
  //( ++i + ++ i )�ǲ���ִ�еģ�
  //����i ��ֵ����3 





//���鶺�ű��ʽ 
	//���鶺�ű��ʽ,���ű��ʽ�����ȼ��Ǻܵ͵ģ�
	//�ȸ�ֵ(=)�����ȼ���. ���ű��ʽ��ֵ�������һ��Ԫ�ص�ֵ 
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


//a��������һ����������,����5����Ա 
//&a��������һ�����������ָ�� 
//����&a + 1ָ��ĵط���ͬ�� a[6] 
//����*(a+1) ��ͬ��a[1] 
//ptr��ͬ a[6], ptr-1�͵�ͬ��a[5] 



}
