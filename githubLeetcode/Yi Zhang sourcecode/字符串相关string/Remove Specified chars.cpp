
#include "stdafx.h"

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
#include <set>
#include <cmath>
#include <stack>
#include <list>
#include <memory>
using namespace std;

void RemoveChars()
{
	char str[]="teeter";
	char remove[]="er";
	set<char> rmSet(remove,remove+2);
	size_t src=0,dst=0;
	do
	{
		if(rmSet.count(str[src])==0)
		{
			str[dst++]=str[src];
		}
		
	}while(str[src++]!='\0');

	cout<<str<<endl;
}

int _tmain(int argc, _TCHAR* argv[]) 
{
	RemoveChars();
	return 0;
}

