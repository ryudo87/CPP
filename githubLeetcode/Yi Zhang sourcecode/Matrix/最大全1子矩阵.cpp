
#include "all.h"

//Largest Rectangle in a Histogram
//复杂度O(n)
int LargestRectangleinaHistogram(int height[], int len)
{
	if(!height) return -1;

	int *lbd=new int[len];
	int *rbd=new int[len];
	//init
	for(int i=0;i<len;++i){
		lbd[i]=i;
		rbd[i]=i;
	}

	for(int i=1,j=len-2;i<len;++i,j--){
		while(lbd[i]>0 && height[i]    <=height[lbd[i]-1]){
			lbd[i]=lbd[lbd[i]-1];
		}
		while(rbd[j]<len-1 && height[j]<=height[rbd[j]+1]){
			rbd[j]=rbd[rbd[j]+1];
		}
	}

	int tempMax=0;
	for(int i=0;i<len;++i){
		if(tempMax< (rbd[i]-lbd[i]+1)*height[i]){
			tempMax=(rbd[i]-lbd[i]+1)*height[i];
		}
		cout<<"cur Area:"<<(rbd[i]-lbd[i]+1)*height[i]<<", tempMax:"<<tempMax<<endl;
	}

	return tempMax;
}

//0-1矩阵最大全1子矩阵
//     问题描述：a[n][m]为n*m矩阵，其所有元素为0或1.求一个子矩阵，使得其所有元素均为1，
//     且该子矩阵包含最多的1.

#define M 5
#define N 5
int matrix[M][N]={{1,0,1,0,1},{1,1,1,1,1},{1,1,1,1,0},{0,1,1,1,1},{1,1,1,1,1}};
int max_all1_rectangle()
{
	int height[N],curMax=0;	memset(height,0, N*sizeof(int));
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			if(matrix[i][j]==1)
				height[j]++;
			else height[j]=0;
		}
		print_array(height,N,"height");
		int area=LargestRectangleinaHistogram(height,N);
		curMax=area>curMax?area:curMax;
	}

	return curMax;
}
int main()
{
	//int height[]={2,1,4,3,2};
	//cout<<LargestRectangleinaHistogram(height,sizeof(height)/sizeof(height[0]))<<endl;
	cout<<"area of max_all1_rectangle: "<<max_all1_rectangle()<<endl;
	return 0;
}
