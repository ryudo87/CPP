//求0，1矩阵的最大连续全1块（可以非规则）
//给一个n/times m的0，1矩阵，求它的面积最大的全1子块。
//要求O(n^2)时间。
//------------------------------------------------------------
//对矩阵做三次扫描, 扫描的次序都是从左到右,从上到下.第一遍将所有为1的元素,依次标一个值,这个值从1开始 例如:
//0 0 0 0 0  // 0 0 0 0 0标注成这样
///0 1 1 0 0  // 0 1 2 0 0
//0 1 0 0 0  // 0 3 0 0 0
//0 0 0 1 0  // 0 0 0 4 0
//0 0 0 1 0  // 0 0 0 5 0
//第二遍 如果 遇到不为0 的元素, 考虑这个元素以及它周围四个元素中,不为0的元素标，求他们的最小值，并将这些元素通标注为这个最小值　像上面，遇到了１　那么将 2和3 标注成 1 。就变成下面这样
//0 0 0 0 0
//0 1 1 0 0
//0 1 0 0 0
//0 0 0 4 0
//0 0 0 4 0
//左后一遍 数一下各种数字的个数，最多的，就是最大全1子块的面积
//(注，这样做，结果是连续的全1区域，很可能是不规则的)
#include <stdio.h>
#define m 4
#define n 7
#define MIN(a,b) ((a)<(b)?(a):(b))
int matrix[][n]={{0,0,1,0,0,0,1},{0,1,1,1,1,1,0},{0,0,0,0,0,0,0},{1,1,1,1,1,1,0}};
void print_matrix()
{	int i,j;
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			printf("%d,",matrix[i][j]);
		}
		printf("\n");
	}
		printf("\n");
}
int main()
{
	int i,j;  unsigned order=1;
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(matrix[i][j]==1) matrix[i][j]=order++;
		}
	}
	print_matrix();
	
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(matrix[i][j]==0) continue;

			if(i>0 && matrix[i-1][j]!=0 )
			{
				 matrix[i][j]=MIN(matrix[i-1][j],matrix[i][j]);
				 matrix[i-1][j]=MIN(matrix[i-1][j],matrix[i][j]);
			}
			
			if(j>0 && matrix[i][j-1]!=0 )
			{
				 matrix[i][j-1]=MIN(matrix[i][j-1],matrix[i][j]);
				 matrix[i][j]=MIN(matrix[i][j-1],matrix[i][j]);
			}

			if(j<n-1 && matrix[i][j+1]!=0 )
			{
				 matrix[i][j+1]=MIN(matrix[i][j+1],matrix[i][j]);
				 matrix[i][j]=MIN(matrix[i][j+1],matrix[i][j]);
			}
			if(i<m-1 && matrix[i+1][j]!=0 )
			{
				 matrix[i][j]=MIN(matrix[i+1][j],matrix[i][j]);
				 matrix[i+1][j]=MIN(matrix[i+1][j],matrix[i][j]);
			}
		}
	}
	print_matrix();

	int *area=(int*)malloc(order*sizeof(int));
	memset(area,0,order*sizeof(int));
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			area[ matrix[i][j] ]++;
		}
	}
	int max=0;
	for(i=1;i<order;++i){
		printf("order:%d,area:%d\n",i,area[i]);
	}
return 0;
}
