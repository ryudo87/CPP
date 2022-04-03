//基本思路：在数组N中，N[0]和N[2*num-1]这两个不用变，N[1]和N[2]交换，然后N[1]和N[4]，N[1]和N[8]....
//然后是N[3]和N[6]?
//N[3]和N[12]，N[3]和N[24]...这就有规律了，总是奇数位分别与该位的2倍，4倍，8倍，16倍...位交换，
//如果该倍数大于总长就取模
//直到该倍数取模后的值与原来相等就找下一个奇数位。但是这个过程要先空跑一遍，因为如果可能交换到某步时已经达到最终目标，
//再走下去就会错了。所以要先找到循环到哪一位就可结束了。


//输入a_1,   a_2,   ...,   a_n,   b_1,   b_2,   ...,   b_n，如何在O(n)的时间，用O(1)的空间，
//将这个序列顺序改为a_1,   b_1,   ...,   a_n,   b_n。


#include "all.h"
int arr[]={1,2,3,4,5,6,7,8,11,22,33,44,55,66,77,88};
void repermute_array()
{
	int oddNum,multiple=2,temp,num=sizeof(arr)/sizeof(arr[0])/2,max=0;
	cout<<num<<endl;
//	  for(oddNum=1;oddNum<num;oddNum+=2){
//		  /*先空跑一遍因为如果可能交换到某步时已经达到最终目标，再走下去就会错了。所以要先找到循环到哪一位就可结束了。*/
//	      while((oddNum*multiple)%(2*num-1)!=oddNum){
//	        max++;
//	        multiple*=2;
//	      }
//	      multiple=2;
//	      if (max>2*num-3) break;
//
//	  }
//
//	  max=oddNum;    /*MAX-2是最大位，由于下面那个循环用了i<max，所以不用max=i就行了*/

	  for(oddNum=1;oddNum<num;oddNum+=2){
	      while((oddNum*multiple)%(2*num-1)!=oddNum){
	    	  max++;

	    	cout<<"swap "<<arr[oddNum]<<" & "<<arr[(oddNum*multiple)%(2*num-1)]<<endl;
	        temp=arr[oddNum];
	        arr[oddNum]=arr[(oddNum*multiple)%(2*num-1)];
	        arr[(oddNum*multiple)%(2*num-1)]=temp;

	        multiple*=2;

	        print_array(arr,sizeof(arr)/sizeof(arr[0]),"arr");
	      }
	      multiple=2;

	      if (max>=2*num-3) break;
	  }

	  print_array(arr,sizeof(arr)/sizeof(arr[0]),"final arr");


}

int main()
{
	repermute_array();
//	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
//		cout<<arr[i]<<endl;
//	}
	return 0;
}
