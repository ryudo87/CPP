//
//题目7. 计算Fibonacci 数 F(n)，O(n)的算法是很trival的。但是有很漂亮简洁的Log(
//                                                      N)算法，思路是利用2*2矩阵表示Fibonacci递推式，然后用二分法的思想球矩阵的N次
//方。


//(Fn  F(n-1) )= (F1  F0)*(A^(n-1))
//A= (1  1
//    1  0)
int A[2][2]={{1,1},{1,0}};

void mult(int a[2][2], int b[2][2])
{
	int c[2][2];
	c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];

	a[0][0]=c[0][0];
	a[0][1]=c[0][1];
	a[1][0]=c[1][0];
	a[1][1]=c[1][1];
}
int logn_fibonacci(int n)
{
	if(n==0) return 0;
	int curM[2][2]={{1,1},{1,0}};
	int res[2][2]={{1,0},{0,1}};
	while(n){
		if(n&1){
			mult(res,curM);
		}
		mult(curM,curM);
		n>>=1;
	}

	return res[0][0];
}
int main()
{
	int i;
	while(cin>>i)
		cout<<logn_fibonacci(i)<<endl;

	return 0;
}
