

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;



int main(int argc, _TCHAR* argv[])
{
	string s[10];

	ifstream infile("temp.txt");
	if(!infile)
		cerr<<"failed to open"<<endl;

	int i=0;
	
	while(getline(infile,s[i%10]))
	{
		//cout<<","<<infile<<endl;
		i++;
	}

	for(int i=0;i<10;i++)
		cout<<s[i]<<endl;
}

