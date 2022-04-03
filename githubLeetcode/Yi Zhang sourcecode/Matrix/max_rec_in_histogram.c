#include <stdio.h>
#include <memory.h>
int h[]={3};
int n=sizeof(h)/sizeof(h[0]);

int main()
{
	if(n<1) return 0;
	int *l=(int*)malloc(n*sizeof(int));
	int *r=(int*)malloc(n*sizeof(int));
	int i,j,tmax=0;
	l[0]=0;r[n-1]=n-1;
	for(i=1;i<n;++i){
		l[i]=i;
		while(l[i]>0&& h[l[i]-1]>=h[i]){
			l[i]=l[l[i]-1];
		}
		printf("l[%d]=%d \n",i,l[i]);

	}
	for(i=n-2;i>=0;--i){
		r[i]=i;
		while(r[i]<n-1 && h[r[i]+1]>=h[i]){
			r[i]=r[r[i]+1];
		}
		printf("r[%d]=%d:,",i,r[i]);
	}
	for(i=0;i<n;i++){
		if(tmax<(r[i]-l[i]+1)*h[i])
			tmax=(r[i]-l[i]+1)*h[i];
			
	}
	printf("max size:%d\n",tmax);
return 0;
}
