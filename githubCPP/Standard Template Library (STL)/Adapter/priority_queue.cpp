
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main()
{
	priority_queue<string,vector<string>, greater<string>> pp;
	string s;
	while(cin>>s)
	{
		pp.push(s);
		cout<<s<<endl;
	}
	int size=pp.size();
	for(int i=0;i<size;i++)
	{
		cout<<pp.top()<<endl;
		pp.pop();
	}




}

