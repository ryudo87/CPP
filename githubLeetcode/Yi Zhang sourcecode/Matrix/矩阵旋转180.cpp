#include "stdafx.h"
#include <iostream>
using namespace std;


void rotate180(int matrix[][2], size_t m, size_t n,int new_matrix[][2])
{
	for(size_t i=0;i<m;i++)
		for(size_t j=0;j<n;++j)
			new_matrix[m-i-1][n-j-1]=matrix[i][j];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int matrix[][2]={	{1,2},	{3,4},	{5,6}};
	int new_matrix[3][2];

	rotate180(matrix,3,2,new_matrix);
		
	for(size_t i=0;i<3;i++){
		for(size_t j=0;j<2;++j)
		{
			cout<<new_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

