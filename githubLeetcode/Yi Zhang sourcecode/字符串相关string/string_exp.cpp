
#include "stdafx.h"
#include <iostream>
#include <string>
//#include "ListNode.h"
#include <vector>
#include <cstdio>
using namespace std;

char s[2002];
int _tmain(int argc, _TCHAR* argv[])
{
	
 char s[2002];
		int i, j, m,n;
	cin>>s;
	m=n=strlen(s);
	for(i=2;i<=n;i++){
		while(n%i==0){
			n/=i;
			for(j=0;j<m-m/i && s[j]==s[j+m/i];j++);
			if(j==m-m/i)  m/=i;
		}
	}
	cout<<strlen(s)/m<<endl;



}

