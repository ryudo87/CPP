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
using namespace std;

void ten2bi(double num)
{
	string res;
	int intpart=static_cast<int>(num);
	double doupart=num-intpart;

	while(intpart){
		if(intpart%2){
			res.insert(0,"1");
		}
		else res.insert(0,"0");
		intpart/=2;
	}
	res.append(".");
	int count=0;
	while(count<6&&doupart!=0){
		doupart*=2;
		if(doupart>=1){
			res.append("1");
			doupart-=1;}
		else{	res.append("0");}

		count++;
	}
	cout<<res<<endl;
}

void bi2ten(string b)
{
	if(b.empty()) return;

	int point=b.find_first_of('.');
	int i=point-1;
	double mul=1;
	double res=0;
	while(i>=0){
		if(b[i]=='1') res+=mul;
			
		mul*=2;
		i--;
	}


	i=point+1;
	mul=0.5;
	while(i<b.length()){
		if(b[i]=='1') res+=mul;
		mul/=2;i++;
	}
	cout<<res<<endl;
}
int main(int argc, _TCHAR* argv[])
{
	
	//ten2bi(12.75);
	string a;
	cout<<(a=="")<<endl;
	cout<<a.empty()<<endl;
	bi2ten("101.01011");
	return 0;
}
