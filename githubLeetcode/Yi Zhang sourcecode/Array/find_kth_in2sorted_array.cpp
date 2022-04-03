#include "all.h"
#include "tree.h"

//Given 2 sorted arrays A and B, find the kth element in the merged array 
//1 O(k) solution immediately, and it can be done with O(1) space. 
//2 O(logk) solution

//A slightly modified version of this problem has been used before: find the median of 2 sorted arrays. This can also be solved by binary search in both A and B, time complexity is log(len(A)) + log(len(B)) 
//
//给定两个有序的数组，长度分别为m和n，求这两个数组中的第K个元素
//问题分析：
//1. 把 A 平均分为前后两个部分，前部分有 x 个元素，后部分有 n-x 个元素（由于 A 是有序的，所以后一部分的所有元素都大于前一部分）。A[x] 为 A 的后一部分中的第一个元素。
//2. 同理把 B 也平均分成前后两个部分，前部分有 y 个元素，后部分有 m-y 个元素。B[y] 是 B 的后一部分中的第一个元素。
//3. 由于两个数组都是被平均分割的，所以可以近似地认为 x = n/2, y = m/2。这里不妨设 A[x] <= B[y]（如果 A[x] > B[y] 处理过程和下面类似）：
//
//
//情况1:
//
//由于在 A 中，A[x] 前面有 x 个元素，在 B 中，B[y] 前面有 y 个元素，并且又有 A[x] <= B[y]，那么，合并以后，A[x]前面原来那些元素必然也在B[y]前面。也就是说，B[y]前面至少会有 x + y 个元素，我们再规定如果 A, B 中有相同元素，则合并后 A 中的元素排在 B 前面，那么归并以后 A[x] 也会排在 B[y] 前面，于是，合并之后 B[y] 至少有 x+y+1 个元素。
//
//如果 k <= x+y+1，也就是说，合并后第 k 个元素必然落在 B[y] 前面。所以，原来在 B 数组中的后一部分（B[y]以及 B[y] 之后）那些元素都不可能包含我们要找到内容（第 k 大元素），所以我们可以把他们排除掉。这样就排除了 B 中一半的内容。
//
//
//情况2:
//
//在 A 中，A[x] 及其后面有 n-x 个元素，除去 A[x] 之后有 n-x-1 个元素，B[y] 及其后面有 m-y 个元素。那么，由于 A[x] <= B[y]，所以合并起来之后，B[y] 后面那些元素必然也在 A[x] 后面，则合并后 A[x] 后面至少有(n-x-1) + (m-y) = (n+m)-(x+y+1) 个元素。
//
//如果 k > x+y+1，也就说，合并后第 k 大的元素必然落在 A[x] 后面。所以，原来在 A 数组中，第一部分（A[x]之前）以及 A[x] 都不可能包含我们要找的元素，所以我们可以把他们排除掉。这样就排除了 A 中一半的内容。
//
//
//总结：
//
//综上所述，对于 k <= x+y+1 还是 k > x+y+1 我们都提出了解决的方案，并且每种方案都能把 A 或者 B 的规模减小一半。减小了一半之后，我们将其作为一个新的问题继续使用上面的算法处理，直到 A 或者 B 减小到足够小：
//1.	A 没有了，这样只需要找出 B 中第 k 大的元素，也就是 B[k]。
//2.	B 没有了，同上结果就是 A[k]。

//Java代码
//1.	public class NumX {  
//    2.	  
//    3.	    private int[] a;  
//    4.	    private int[] b;  
//    5.	      
//    6.	    public int find(int aLeft, int aRight, int bLeft, int bRight, int k) {  
//        7.	        int aMid = (aLeft + aRight) / 2;  
//        8.	        int bMid = (bLeft + bRight) / 2;  
//        9.	          
//        10.	        if (aLeft > aRight)  
//            11.	            return b[bLeft+k-1];  
//        12.	        if (bLeft > bRight)  
//            13.	            return a[aLeft+k-1];  
//        14.	          
//        15.	        if (a[aMid] <= b[bMid]) {  
//            16.	            if (k <= (aMid-aLeft) + (bMid-bLeft) + 1)  
//                17.	                return find(aLeft, aRight, bLeft, bMid-1, k);  
//            18.	            else  
//                19.	                return find(aMid+1, aRight, bLeft, bRight, k-(aMid-aLeft)-1);  
//            20.	        } else {  
//                21.	            if (k <= (aMid-aLeft) + (bMid-bLeft) + 1)  
//                    22.	                return find(aLeft, aMid-1, bLeft, bRight, k);  
//                23.	            else  
//                    24.	                return find(aLeft, aRight, bMid+1, bRight, k-(bMid-bLeft)-1);  
//                25.	        }  
//        26.	    }  
//    27.	      
//    28.	    public static void main(String[] args) {  
//        29.	        NumX n = new NumX();  
//        30.	        n.a = new int[] {1, 4, 6};  
//        31.	        n.b = new int[] {5, 8, 9};  
//        32.	        System.out.println(n.find(0, 2, 0, 2, 3));  
//        33.	    }  
//    34.	}  



//k from 1
int linear_find_kth_in2sorted_array(int s[], int slen, int t[], int tlen, int k)
{
	int i=0,j=0,r=0;
	for(;k>0&& (i<slen||j<tlen) ;--k){
		if( ( (i<slen&&j<tlen)&&s[i]<t[j])
				|| j>=tlen){
			r=s[i++];
		}
		else{
			r=t[j++];
		}
	}


	return r;
}

int find_kth_in2sorted_array(int s[], int slen, int t[], int tlen, int k)
{

	if(k<=0 || k>slen+tlen) return -1;
	if(slen<=0){
		return t[k-1];
	}
	if(tlen<=0){
		return s[k-1];
	}
	int x=(slen-1)/2;
	int y=(tlen-1)/2;

	if(s[x]<t[y]){
		if(k<=x+y+1){
			return find_kth_in2sorted_array(s,slen,t,tlen/2,k);
		}
		else{
			return find_kth_in2sorted_array(s+x+1,slen-x-1,t,tlen,k-x-1);
		}
	}
	else{
		if(k<=x+y+1){
			return find_kth_in2sorted_array(s,slen/2,t,tlen,k);
		}
		else{
			return find_kth_in2sorted_array(s,slen, t+y+1,tlen-y-1,k-y-1);
		}
	}

}




TEST(find_kth_in2sorted_array, RANDOM)
{
	for(int i=0;i<5;++i){
		int *s,*t,slen=0,tlen=0;
		randGenArr(s,slen,true);
		randGenArr(t,tlen,true);

		print_array<int>(s,slen,"s");
		print_array<int>(t,tlen,"t");

		for(int k=1;k<=slen+tlen;++k){cout<<"k="<<k<<endl;
			ASSERT_EQ( linear_find_kth_in2sorted_array(s,slen,t,tlen,k) , find_kth_in2sorted_array(s,slen,t,tlen,k))<<k;
		}
	}

}
