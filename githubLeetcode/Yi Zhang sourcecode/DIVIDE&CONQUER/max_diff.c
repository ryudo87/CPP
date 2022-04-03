#include <stdio.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int get_max_diff(int arr[],int n,int* tmax,int* tmin)
{

	if(n==1){ *tmax=*tmin=arr[0];return INT_MIN; }

int t1,t2,t3,t4;
int d1=get_max_diff(arr,(n+1)/2,&t1,&t2);
int d2=get_max_diff(arr+(n+1)/2,n/2,&t3,&t4);

*tmax=max(t1,t3);
*tmin=min(t2,t4);

return max(t1-t4, max(d1,d2) );
}
int main(){

int arr[]={3,1};

int tmax,tmin;
int d1,d2;
int n=sizeof(arr)/sizeof(arr[0]);


int t1,t2,t3,t4;
d1=get_max_diff(arr,(n+1)/2,&t1,&t2);
d2=get_max_diff(arr+(n+1)/2,n/2,&t3,&t4);

int max_d= max(t1-t4, max(d1,d2) );

printf("%d\n",max_d);
	return 2;
}
