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

#define N 4
int m[N][N]={{3,2,6,3},{1,10,0,5},{1,2,2,1},{1,0,2,3}};
//int m[N][N]={{3,2},{1,2}};

int sum[N][N];
string next[N][N];

int walk_matrix(int x,int y)
{
	if(x==N-1 && y==N-1) { sum[x][y]=m[x][y]; return sum[x][y];}

	if( sum[x][y]!=0 ){
		return sum[x][y];
	}


	int rightward=0,downward=0;
	if(x+1<N){
		 downward=walk_matrix(x+1,y);
	}
	if(y+1<N){
		 rightward=walk_matrix(x,y+1);
	}

	if(downward>rightward){
		next[x][y]="down";
		sum[x][y]=downward+m[x][y];
	}
	else {
		next[x][y]="right";
		sum[x][y]=rightward+m[x][y];
	}

	return sum[x][y];
}

void get_path()
{
	int x=0,y=0;
	cout<<"max:"<<sum[0][0]<<endl;
	while(next[x][y]=="down" || next[x][y]=="right"){
		cout<<x<<','<<y<<endl;
		
		if(next[x][y]=="down")
			x++;
		else y++;
	}
}
void main(void)   
{  
	int res=walk_matrix(0,0);
	get_path();
}