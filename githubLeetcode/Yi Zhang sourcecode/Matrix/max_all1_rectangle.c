#include <stdio.h>
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
int main()
{
  max_all1_rectangle();
}
