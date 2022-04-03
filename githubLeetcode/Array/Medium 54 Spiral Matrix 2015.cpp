#include "all.h"

//Spiral Matrix
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3],
// [ 4, 5, 6],
// [ 7, 8, 9 ]

//You should return [1,2,3,6,9,8,7,4,5].



vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> res;
	if(matrix.size()<=0) return res;
	int row=matrix.size();
	int col=matrix[0].size();

	int top=0,bottom=row-1,left=0,right=col-1;
	while(top<=bottom && left<=right){
		for(int j=left;j<=right;++j){

			res.push_back(matrix[top][j]);
			//print_vector<int> (res,"res");
		}
		++top;
		if(top>bottom ) break;

		for(int i=top;i<=bottom;++i){
			res.push_back(matrix[i][right]);
			//print_vector<int> (res,"res");
		}
		--right;
		if(left>right) break;

		for(int j=right;j>=left;--j){
			res.push_back(matrix[bottom][j]);
			//print_vector<int> (res,"res");
		}
		--bottom;
		if(top>bottom ) break;

		for(int i=bottom;i>=top;--i){
			res.push_back(matrix[i][left]);
			//print_vector<int> (res,"res");
		}
		++left;
	}

	return res;
}

class A
{
public:
	void inline virtual f(){cout<<"f"<<endl;};
};
int main()
{
	A a;
	a.f();
	int arr[][4]={{1,2,3,0},{4,5,6,-1},{7,8,9,-2}};

	vector<vector<int> > matrix=init_matrix<int,3,4>(arr);
	print_matrix<int>(matrix,"matrix");
	print_vector<int>(spiralOrder(matrix), "spiral");
       return 0;
}



