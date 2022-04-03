

#include "all.h"


#define M 3
#define N 4

pair<int, int> find_in_matrix(vector < vector<int> > matrix, int target)
{
	pair<int, int> res=pair<int,int>(-1,-1);
	int begin=0,end=M*N-1,mid;
	while(begin<=end){
		//int a=matrix[begin/N][begin%N],b=matrix[end/N][end%N];
		int midIndex=(begin+end)/2;
		mid=matrix[midIndex/N][midIndex%N];
		if(mid==target){
			res.first=midIndex/N;
			res.second=midIndex%N;
			return res;
		}
		else if(mid<target){
			begin=midIndex+1;
		}
		else end=midIndex-1;
	}


	return res;
}


int main(){
	vector < vector<int> > matrix(M);

	for(int i=0;i<M;++i)
		for(int j=0;j<N;j++){
			matrix[i].push_back(3+j*2+N*i);
		}

	print_matrix<int>(matrix,"matrix");
	int target;
	cin>>target;
	pair<int,int> res=find_in_matrix(matrix, target);
	cout<<res.first<<","<<res.second<<endl;
}
