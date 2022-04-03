
#include "all.h"

//Largest Rectangle in a Histogram

//Largest Rectangle in Histogram
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given height = [2,1,5,6,2,3],
//return 10.
//
//

//复杂度O(n)
//80 milli secs
int largestRectangleArea(vector<int> &height) 
{
    int len=height.size();
    int *lbd=new int[len];
    int *rbd=new int[len];
    //init
    for(int i=0;i<len;++i){
        lbd[i]=i;
        rbd[i]=i;
    }
    
    for(int i=1,j=len-2;i<len;++i,j--){
        while(lbd[i]>0 && height[i]    <=height[lbd[i]-1]){
            lbd[i]=lbd[lbd[i]-1];
        }
        while(rbd[j]<len-1 && height[j]<=height[rbd[j]+1]){
            rbd[j]=rbd[rbd[j]+1];
        }
    }
    
    int tempMax=0;
    for(int i=0;i<len;++i){
        if(tempMax< (rbd[i]-lbd[i]+1)*height[i]){
            tempMax=(rbd[i]-lbd[i]+1)*height[i];
        }
        
    }
    
    return tempMax;
    
}


int LargestRectangleinaHistogram(int height[], int len)
{
	if(!height) return -1;

	int *lbd=new int[len];
	int *rbd=new int[len];
	//init
	for(int i=0;i<len;++i){
		lbd[i]=i;
		rbd[i]=i;
	}

	for(int i=1,j=len-2;i<len;++i,j--){
		while(lbd[i]>0 && height[i]    <=height[lbd[i]-1]){
			lbd[i]=lbd[lbd[i]-1];
		}
		while(rbd[j]<len-1 && height[j]<=height[rbd[j]+1]){
			rbd[j]=rbd[rbd[j]+1];
		}
	}

	int tempMax=0;
	for(int i=0;i<len;++i){
		if(tempMax< (rbd[i]-lbd[i]+1)*height[i]){
			tempMax=(rbd[i]-lbd[i]+1)*height[i];
		}
		cout<<"cur Area:"<<(rbd[i]-lbd[i]+1)*height[i]<<", tempMax:"<<tempMax<<endl;
	}

	return tempMax;
}


int main()
{
	//int height[]={2,1,4,3,2};
	//cout<<LargestRectangleinaHistogram(height,sizeof(height)/sizeof(height[0]))<<endl;
	cout<<"area of max_all1_rectangle: "<<max_all1_rectangle()<<endl;
	return 0;
}


#define M 5
#define N 5
int matrix[M][N]={{1,0,1,0,1},{1,1,1,1,1},{1,1,1,1,0},{0,1,1,1,1},{1,1,1,1,1}},h[N],l[N],r[N];
int max_all1_rectangle()
{
	int temp_max=0,i,j;
	for( i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matrix[i][j]==1) h[j]++;
			else h[j]=0;
			
			printf("h[%d]=%d:",j,h[j]);
		}
		printf("\n");
		for( j=0;j<N;j++){
            //设置l[],r[]数组代表某行高度为>=h的左右边界。
			l[j]=j;
			while(l[j]>0 && h[j]<=h[l[j]-1]) {
				l[j]=l[l[j]-1];
			}	
			
			printf("l[%d]=%d:,",j,l[j]);
		}
		printf("\n");
		for( j=N-1;j>=0;j--)
		{
			r[j]=j;
			while(r[j]<N-1 && h[j]<=h[r[j]+1])
				r[j]=r[r[j]+1];
			printf("r[%d]=%d:,",j,r[j]);
		}
		printf("\n");
		for( j=0;j<N;j++)
		{
			if(temp_max < h[j] * (r[j]-l[j]+1)){
				temp_max= h[j] * (r[j]-l[j]+1);
				printf("temp max size:%d, left:%d,right:%d,height:%d,row:%d\n",temp_max,l[j],r[j],h[j],i);
			}
		}
	}
	printf("max size:%d",temp_max);
}


