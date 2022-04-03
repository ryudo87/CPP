#include "all.h"
#include <unistd.h>
//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// 8 milli secs
int climbStairs(int n) {
	int a=1,b=2;
	if(1==n) return 1;
	if(2==n) return 2;
	for(int i=3;i<=n;++i){
		int t=a+b;
		a=b;
		b=t;
	}
	return b;

}

int main()
{

	//vector< vector<int> > res=combinationSum();

	//print_matrix<int>(res,"combine");
	cout<<"done"<<endl;
	return 0;
}
