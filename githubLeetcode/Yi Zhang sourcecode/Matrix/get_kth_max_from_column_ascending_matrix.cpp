

//Find the Nth element of a sorted NxN matrix       Aug. 18, 2010 11:14pm
//
//Find an algorithm that finds the Nth element (in value) of a sorted NxN matrix of, say, integers. Each row and each column of the matrix is sorted.
//
//solutions sorted from worst to best.
//- N^2*log N time, N^2 space: sort all numbers, keep the N-th.
//
//- N^2*log N time, N space: scan all numbers, maintaining a heap of the N smallest.
//
//- N*log N time, N space: initialize N 'walkers' which will descend on each of the N columns, starting from the top. At the beginning they're on top. Put them in heap indexed by the value at which they point. Iterate N times: the walker with the smallest value goes down. After N-1 iterations, the smallest value among the walkers is the element we're looking for.
#include "all.h"

//1)
struct element
{
	int row;
	int col;
	int val;
	element(int r,int c,int v):row(r),col(c),val(v){}
	bool operator <(const element& r) const
	{
		return val>r.val;
	}
};
int bruteForce_Find_Nth_element_sorted_matrix(const vector< vector<int> >& mat,int N)
{
	vector<int> vec;
	for(int i=0;i<mat.size();++i)
		vec.insert(vec.end(),mat[i].begin(),mat[i].end());
	sort(vec.begin(),vec.end());
	cout<<vec[N-1]<<endl;
	return vec[N-1];
}
int Find_Nth_element_sorted_matrix(const vector< vector<int> >& mat,int N)//N from 1
{
	int row=mat.size();
	int col=mat[0].size();
	priority_queue<element> pq;
	for(int j=0;j<col;++j){
		pq.push(element(0,j,mat[0][j]));
	}
	for(int it=0;it<N-1;++it){
		element e=pq.top();pq.pop();
		if(e.row<row-1)
		    pq.push(element(e.row+1,e.col,mat[e.row+1][e.col]));
	}

	return pq.top().val;
}

TEST(Find_Nth_element_sorted_matrix,RANDOM)
{
	vector< vector<int> > mat=randGen2DVector(true,true);
	print_matrix<int> (mat);
	for(int N=1;N<=mat.size()*mat[0].size();++N)
	ASSERT_EQ(bruteForce_Find_Nth_element_sorted_matrix(mat,N), Find_Nth_element_sorted_matrix(mat,N));
}

//2)
struct num_loc
{
	int val;int row;int col;
	bool operator < (const num_loc& rop) const {
		return val<rop.val;
	};
	num_loc(int v,int r,int j){
		val=v;row=r;col=j;
	}
};

#define N 12
#define m 4
#define n 3

int matrix[][3]={{2,1,-1},{4,3,11},{7,5,12},{15,8,13}};
int get_Kth_max(int k)
{
	assert(k<=N && m>0 && n>0);
	priority_queue<int> pq;
	priority_queue< num_loc > pool_pq;
	for(int j=0;j<n;j++){
		pq.push(matrix[m-1][j]);//last row

		num_loc *temp=new num_loc(matrix[m-2][j],m-2,j);
		pool_pq.push(*temp);
	}

	for(int i=1;i<k;++i){

		pq.pop();
		if(!pool_pq.empty()){
			const num_loc nl=pool_pq.top();
			pool_pq.pop();
			pq.push(nl.val);
			int row=nl.row;int col=nl.col;
			if(row==0){
				continue;
			}

			num_loc *temp=new num_loc(matrix[row-1][col],row-1,col);
			pool_pq.push(*temp);
		}
	}
	return pq.top();
}

int get_Kth_max2(int k)
{
	assert(k>0 && k<=N && m>0 && n>0);

	priority_queue< num_loc > pool_pq;
	for(int j=0;j<n;j++){
		num_loc *temp=new num_loc(matrix[m-1][j],m-1,j);
		pool_pq.push(*temp);
	}

	for(int i=1;i<k;++i){

		if(!pool_pq.empty()){
			const num_loc nl=pool_pq.top();
			pool_pq.pop();

			int row=nl.row;int col=nl.col;
			if(row==0){
				continue;
			}

			num_loc *temp=new num_loc(matrix[row-1][col],row-1,col);
			pool_pq.push(*temp);
		}
	}
	return pool_pq.top().val;
}
int main()
{
	//cout<<get_Kth_max(1)<<endl;
	cout<<"1th:"<<get_Kth_max2(1)<<endl;
	cout<<"2th:"<<get_Kth_max2(2)<<endl;
	cout<<"3th:"<<get_Kth_max2(3)<<endl;
	cout<<"4th:"<<get_Kth_max2(4)<<endl;
	cout<<"5th:"<<get_Kth_max2(5)<<endl;
	cout<<"6th:"<<get_Kth_max2(6)<<endl;
	cout<<"7th:"<<get_Kth_max2(7)<<endl;
	cout<<"11th:"<<get_Kth_max2(11)<<endl;
	cout<<"12th:"<<get_Kth_max2(12)<<endl;
	cout<<"13th:"<<get_Kth_max2(13)<<endl;

	return 0;
}
