#include <cstdio>
#include <iostream>
#include "arrayOP.h"
using namespace std;
#define N 4
#define M 2
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	//for(int i=0;i<M;++i){
	//	for(int j=0;j<N;++j)
	int i=0,j=1,k=1,count=0;
	int old=arr[1],n;
	//arr[1]=-1;
	while(count < M*N-2){
			//temp=arr[N*i+j];
			//arr[N*i+j]=arr[M*j+i];
			n=arr[M*(k%N)+k/N];
		arr[M*(k%N)+k/N]=old;
			count++;
			k=M*(k%N)+k/N;
					old=n;
			//i=(j+1)/N;j=(j+1)%N;
		print_array(arr,N*M,"arr");
	}
	
	print_array(arr,N*M,"arr");

	return 0;
}
