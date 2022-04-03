#include "all.h"
//Spiral Matrix II
//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

vector<vector<int> > generateMatrix(int n)
{
	vector<vector<int> > mat(n, vector<int>(n));
	int top=0,bottom=n-1,left=0,right=n-1, cur=1;
	while(top<=bottom && left<=right)
	{
		for(int j=left;j<=right;++j){
			mat[top][j]=cur++;
		//	print_matrix<int>(mat,"matrix");
		}
		++top;
		if(cur>n*n) break;

		for(int i=top;i<=bottom;++i){
			mat[i][right]=cur++;
		//	print_matrix<int>(mat,"matrix");
		}
		--right;
		if(cur>n*n) break;

		for(int j=right;j>=left;--j){
			mat[bottom][j]=cur++;
			//print_matrix<int>(mat,"matrix");
		}
		--bottom;
		if(cur>n*n) break;

		for(int i=bottom;i>=top;--i){
			mat[i][left]=cur++;
			//print_matrix<int>(mat,"matrix");
		}
		++left;
	}

	return mat;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > mat=generateMatrix(n);
	print_matrix<int>(mat,"matrix");

       return 0;
}
