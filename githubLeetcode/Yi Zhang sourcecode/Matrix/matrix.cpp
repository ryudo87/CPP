#include "stdafx.h"
#include <iostream>
using namespace std;

void modify_matrix(int matrix[][4], size_t m, size_t n)
{
	for(size_t i=0;i<m;i++)
		for(size_t j=0;j<n;++j)
			if(matrix[i][j]==1)
			{
				matrix[i][0]=1;
				matrix[0][j]=1;
			}
	for(size_t i=1;i<m;i++)
		for(size_t j=1;j<n;++j)
			matrix[i][j]=matrix[0][j] | matrix[i][0];

	if(matrix[0][0]==1)
	{
		for(size_t i=0;i<m;i++)
			matrix[i][0]=1;
		for(size_t i=0;i<n;i++)
				matrix[0][i]=1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int matrix[][4]={	{1,0,0,1},	{0,0,1,0},	{0,0,0,0}};

	modify_matrix(matrix, 3,4);

	for(size_t i=0;i<3;i++){
		for(size_t j=0;j<4;++j)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}

