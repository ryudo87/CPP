#include "all.h"
#define N 3
int	m[N][N]={{2,3,5},{1,2,3},{-1,4,6}};
class RecSum
{
int colSum[N][N];
public:
	RecSum(){
		for(unsigned i=0;i<N;i++)	colSum[i][0]=m[i][0];
		for(unsigned i=0;i<N;i++)
			for(unsigned j=1;j<N;j++)
				colSum[i][j]=colSum[i][j-1]+m[i][j];
		print_matrix<3>(m,"m");
		print_matrix<N>(colSum,"colSum");
	}
	void update(int x,int y,int v){
		for(unsigned j=y;j<N;++j){
			colSum[x][j]=colSum[x][j]+v-m[x][y];
		}
		m[x][y]=v;
		
		print_matrix<N>(m,"m");
		print_matrix<N>(colSum,"colSum");
	}
	int query(int x1, int y1, int x2,int y2){
		int sum=0;
		for(unsigned i=x1;i<=x2;++i){
			if(y1>0) sum+=colSum[i][y2]-colSum[i][y1-1];
			else sum+=colSum[i][y2];
		}
		return sum;
	}
};


int main()
{
	RecSum rs;
	rs.update(0,0,0);
	cout<<rs.query(0,1,1,2)<<endl;
}
