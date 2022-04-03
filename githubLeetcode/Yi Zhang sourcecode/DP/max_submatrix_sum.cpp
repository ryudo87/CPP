
#include "all.h"

//问题一（最大和子矩阵） ： 有一个 m x n 的矩阵，矩阵的元素可正可负。请找出该矩阵的一个子矩阵（方块），
//使得其所有元素之和在所有子矩阵中最大。

#define N 4
#define M 4
//int matrix[M][N]={{0,-2,-7,0},{9,2,-6,2},{-4,1,-4,1},{-1,8,0,-2}};

int maxSubArray(int* arr, int len)
{
	int b=0,sum=-100;
	for(int i=0;i<len;++i){
		if(b>0) b+=arr[i];
		else b=arr[i];
		if(b>sum) sum=b;
	}
	return sum;
}
int max_submatrix_sum()
{
	int sum=-100;
	int *b=new int[N];
	for(int i=0;i<M;i++){
		for(int k=0;k<N;k++)
		{
			b[k]=0;
		}
		for(int j=i;j<N;j++){
			for(int k=0;k<N;k++){
				b[k]+=matrix[j][k];
			}
			int temp=maxSubArray(b,N);
			if(temp>sum)
				sum=temp;
		}
	}

	return sum;
}
int main()
{
	cout<<max_submatrix_sum()<<endl;
	return 0;
}
