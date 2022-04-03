#include "all.h"


//1) time:O(1), space:O(n)
vector<int> vec;

void preprocess(int arr[],int n)
{
	if(n<=0) return;
	vec.push_back(arr[0]);
	for(int i=1;i<n;++i){
		vec.push_back(vec[i-1]+arr[i]);
	}
}
int range_sum_query(int i,int j)
{

	if(0==i) return vec[j];
	return vec[j]-vec[i-1];
}


//2) n^1/2 space/time complexity

void preprocess_sqrt(int arr[],int n)
{
	if(n<=0) return;
	int root=sqrt(n);
	int sum=0;
	for(int i=0;i<n;++i){
		sum+=arr[i];
		if((i+1)%root==0){
			vec.push_back(sum);
			sum=0;
		}
	}

}

int range_sum_query_sqrt(int beg,int end,int arr[], int n)
{
	if(!arr || beg>end)	exit(1);

	int root=sqrt(n), sum=0;
	for(int i=beg;i<=end;){
		if(i%root==0 && end-i>=root-1){
			sum+=vec[i/root];
			i+=root;
		}
		else{
			sum+=arr[i];
			++i;
		}
	}

	return sum;
}


#define N 12
#define m 4
#define n 3

int sumMatrix[m+1][n+1];

template<int row,int col>
void preprocess_matrix(int matrix[row][col])
{
	sumMatrix[1][1]=matrix[0][0];
	for(int i=2;i<=m;++i){
		sumMatrix[i][0]=0;
		sumMatrix[i][1]=sumMatrix[i-1][1]+matrix[i-1][0];
	}
	for(int i=2;i<=n;++i){
		sumMatrix[0][i]=0;
		sumMatrix[1][i]=sumMatrix[1][i-1]+matrix[0][i-1];
	}

	for(int i=2;i<=m;++i){
		for(int j=2;j<=n;++j){
			sumMatrix[i][j]=sumMatrix[i-1][j]+sumMatrix[i][j-1]-sumMatrix[i-1][j-1]+matrix[i-1][j-1];
		}
	}
}

int sum_query_submatrix(int x1,int y1,int x2,int y2)
{
	return sumMatrix[x2+1][y2+1]-sumMatrix[x2+1][y1]-sumMatrix[x1][y2+1]+sumMatrix[x1][y1];
}
int main()
{

//	int arr[]={5,17,2,16,4,3,19,1};
//	preprocess_sqrt(arr,sizeof(arr)/sizeof(arr[0]));
//	cout<<range_sum_query_sqrt(1,2,arr,sizeof(arr)/sizeof(arr[0]))<<endl;


	int matrix[][3]={{2,1,-1},{4,3,11},{7,5,12},{15,8,13}};
	preprocess_matrix<m,n>(matrix);
	print_matrix<int,m+1,n+1>(sumMatrix);
	cout<<sum_query_submatrix(0,0,3,2)<<endl;
	return 0;
}
