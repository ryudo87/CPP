
#include "all.h"

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


#define M 5
#define N 5
int matrix[M][N]={{1,0,1,0,1},{1,1,1,1,1},{1,1,1,1,0},{0,1,1,1,1},{1,1,1,1,1}},h[N],l[N],r[N];
int max_all1_rectangle()
{
	int temp_max=0,i,j;
	for( i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matrix[i][j]==1) h[j]++;
			else h[j]=0;
			
			printf("h[%d]=%d:",j,h[j]);
		}
		printf("\n");
		for( j=0;j<N;j++){
            //设置l[],r[]数组代表某行高度为>=h的左右边界。
			l[j]=j;
			while(l[j]>0 && h[j]<=h[l[j]-1]) {
				l[j]=l[l[j]-1];
			}	
			
			printf("l[%d]=%d:,",j,l[j]);
		}
		printf("\n");
		for( j=N-1;j>=0;j--)
		{
			r[j]=j;
			while(r[j]<N-1 && h[j]<=h[r[j]+1])
				r[j]=r[r[j]+1];
			printf("r[%d]=%d:,",j,r[j]);
		}
		printf("\n");
		for( j=0;j<N;j++)
		{
			if(temp_max < h[j] * (r[j]-l[j]+1)){
				temp_max= h[j] * (r[j]-l[j]+1);
				printf("temp max size:%d, left:%d,right:%d,height:%d,row:%d\n",temp_max,l[j],r[j],h[j],i);
			}
		}
	}
	printf("max size:%d",temp_max);
}


