//1. 一个金字塔，有n层，第i层有i个数，有点类似倒置的杨辉三角那种
//让你找出一条路从塔顶到塔底，使得这条路链接的节点和最小
//这个用hashmap存层数和路径长度值，从底层向上遍历
#include "all.h"

//memorization
template<int LEVEL>
int get_min_sum_path(int matrix[LEVEL][LEVEL],int curlevel,int col)
{
	if(curlevel==LEVEL-1)
		return matrix[curlevel][col];
	int d1=get_min_sum_path(matrix,curlevel+1,col);
	int d2=get_min_sum_path(matrix,curlevel+1,col+1);
	return min(d1,d2)+matrix[curlevel][col];
}
int main()
{

	int matrix[][4]={{3},{7,5},{1,6,4},{3,2,8,2}};
	cout<<get_min_sum_path<4>(matrix,0,0)<<endl;
	return 0;
}
