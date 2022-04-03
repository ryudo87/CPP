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
using namespace std;
#define NHASH 5
#define MULT 31

void rotate_array()
{
	int a[]={0,1,2,3,4,5,6};int n=7;
	int i=4,j=0;
	int t=a[0];
	while((j+i)%n!=0){
		a[j]=a[(j+i)%n];
		j=(j+i)%n;
	}
	a[j%n]=t;
}

void reverse(int arr[],int len)
{
	for(int i=0;i<len-i-1;++i){
		int t=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=t;
	}
}
void rotate_array2()
{
	int a[]={0,1,2,3,4,5,6};int n=7;
	int i=4,j=0;
	reverse(a,i);
	reverse(a+i,n-i);
	reverse(a,n);
}
void main(void)   
{   
	rotate_array2();
	
}