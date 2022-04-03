
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

int nextArr[100];
void get_next(string T)
{
	size_t i=1;nextArr[1]=0;int j=0;
	while(i<T.length())
	{
		if(j==0||T[i]==T[j])
		{
			++i;++j;

			if(T[i]!=T[j]) nextArr[i]=j;
			else nextArr[i]=nextArr[j];
		}
		else
		{
			j=nextArr[j];
		}
	}
}
int Index_KMP(string s, string t, int pos)
{
	size_t i=pos,j=1;
	while(i<s.length()&&j<t.length())
	{
		if(j==0||s[i]==t[j]){++i,++j;}
		else j=nextArr[j];
	}
	if(j>t.length())
		return i-t.length();
	else return 0;
}
int main()
{

	string target="0ababc";
	string src="0abababc";
	get_next(target);
	cout<<Index_KMP(src,target,1)<<endl;
	return 0;
}





