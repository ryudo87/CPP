#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "arrayOP.h"
int get_inversions(int* arr,int len)
{
	if(!arr || len<=1 ) return 0;
	print_array(arr,len,"arr");
	int r1=get_inversions(arr,(len+1)/2);
	int r2=get_inversions(arr+(len+1)/2,len/2);
	print_array(arr,len,"arr");
	
	int i=(len-1)/2,j=len-1,right=len/2;
	int r3=0;
	int *temp=(int*)malloc(len*sizeof(int));
	temp+=len-1;
	while(i>=0 || j>(len-1)/2)
	{	if(i<0){(*temp)=arr[j--];}
		else if(j<=(len-1)/2){(*temp)=arr[i--];}
		else if(arr[i]>arr[j]){r3+=right;(*temp)=arr[i--];}
		else{
			right--;
			(*temp)=arr[j--];
		}
		temp--;
	}
	temp++;

	//print_array(arr,len,"arr");
	size_t sz=(size_t)len;
	memcpy((void*)arr,(void*)temp,sizeof(int)*sz);
	free(temp);
	print_array(arr,len,"arr");
	return r1+r2+r3;
}
int main()
{
	int N;
	scanf("%d",&N);
	int *arr=(int*)malloc(N*sizeof(int));
	int i,j;
		srand((unsigned)time(NULL)); 
	for(i=0;i<N;++i){
		arr[i]=(int)(rand()%10);
		
		//printf("%d,",arr[i]);
	}
	print_array(arr,N,"arr");
	printf("inversions #:%d\n",get_inversions(arr,N));
   
	print_array(arr,N,"arr");
}
