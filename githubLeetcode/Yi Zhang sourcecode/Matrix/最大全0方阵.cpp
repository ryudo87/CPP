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
#define N 3


void main(void)   
{
	int m[4][4]={{1,0,1,1},{0,0,0,0},{1,0,0,0},{0,0,0,0}};
	int tmp[4][4]={0};int max=1;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(m[i][j]==1){
				tmp[i][j]=0;
			}
			else{
				if(i-1>=0 && j-1>=0) 
					tmp[i][j]=min(min(tmp[i-1][j],tmp[i][j-1]),tmp[i-1][j-1])+1;
				else tmp[i][j]=1;

				if(tmp[i][j]>max) max=tmp[i][j];
			}
		}
	}
	cout<<max<<endl;
}