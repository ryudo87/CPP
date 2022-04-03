#include "all.h"


//Jump Game
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.


//my recursion method:time out!!
//bool *visited;
//bool jump(int A[],int n,int index)
//{
//
//	if(index+A[index]>=n-1)	return true;
//	for(int step=A[index];step>1;--step){
//		if(index+step<n && visited[index+step]==false){
//			visited[index+step]=true;
//			if(jump(A,n,index+step))
//				return true;
//		}
//	}
//
//	return false;
//}
//bool canJump(int A[], int n) {
//	if(!A || 0==n){
//		return false;
//	}
//	visited=new bool[n];
//
//	for(int i=1;i<n;++i)	visited[i]=false;
//	return jump(A,n,0);
//}





//Dynamic Programming is applied to solve this question,
//while I think time complexity of O(n^2) is not good enough. Do you have a better idea?

//    bool canJump(int A[], int n) {
//
//        bool ATag[n];
//
//        for (int i = n - 1; i >= 0; --i)
//        {
//            ATag[i] = false;
//            int maxReach = A[i] + i;
//
//            if (maxReach >= n - 1)
//            {
//                ATag[i] = true;
//                continue;
//            }
//
//            for (int j = maxReach; j > i; --j)
//            {
//                if (ATag[j])
//                {
//                    ATag[i] = true;
//                    break;
//                }
//            }
//        }
//
//        return ATag[0];
//    }





//Here is a better solution.
//Greedy search performs better than Dynamic programming in solving this problem.

//52ms
//bool canJump(int A[], int n) {
//        // Start typing your C/C++ solution below
//        // DO NOT write int main() function
//
//        if (1 == n)
//            return true;
//
//        int i = 0;
//
//        while (i < n)
//        {
//            int currMax = A[i] + i;
//
//            if (0 == A[i])
//                return false;
//            if (currMax >= n - 1)
//                return true;
//
//            int tmpMax = 0;
//            for (int j = i + 1; j <= currMax; ++j)
//            {
//                if (A[j] + j > tmpMax)
//                {
//                    tmpMax = A[j] + j;
//                    i = j;
//                }
//            }
//        }
//
//        return (i >= n - 1);
//    }




//44 milli secs
//bool canJump(int A[], int n)
//{
//    int k = A[0];
//    int i = 1;
//
//    while(i <= k && i < n)
//    {
//        if (k < (A[i]+i)) k =(A[i]+i); //furthest we could jump so far
//        ++i;
//    }
//
//    return i>=n;
//}
int main()
{
	int A[]={3,2,1,0,4};
	cout<<canJump(A,sizeof(A)/sizeof(A[0]))<<endl;
	return 0;
}
