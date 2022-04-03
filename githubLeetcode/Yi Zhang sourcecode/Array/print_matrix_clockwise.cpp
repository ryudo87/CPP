

#include "all.h"
#include "tree.h"


void print_circle(vector< vector<int> > ma,int col,int row,int startX,int startY)
{
	int endX=col-1-startX;
	int endY=row-1-startY;

	print_row_increase(ma,col,row,startY, startX,endX);
	if(startY<endY)
		print_col_increase();
	if(startX<endX && startY < endY)
		print_row_decrease();
	if(startX<endX && startY <endY -1)
		print_col_decrease();
}

void print_matrix_clockwise(vector< vector<int> >  ma, int col, int row)
{
	if(ma.empty() || col<=0 || row<=0)
		return;
	int startX=0,startY=0;

	while(col>startX*2 && row > startY*2)
	{
		print_circle(ma,col,row,startX,startY);
		++startX;
		++startY;
	}


}
int main()
{
	int M,N;
	cin>>M;cin>>N;

	vector < vector<int> > matrix(M);

	for(int i=0;i<M;++i)
		for(int j=0;j<N;j++){
			matrix[i].push_back(3+j*2+N*i);
		}

	print_matrix<int>(matrix,"matrix");

	print_matrix_clockwise(matrix,N,M);
	return 1;
}
