
int arr[]={3,2,8,1,1};
void swap(int left,int right)
{
	int tmp=arr[left];arr[left]=arr[right];arr[right]=tmp;
}
void quick_sort(int first, int last)
{
	if(first>=last) return;

	int pivot=arr[first];
	int left=first;
	int right=last;

	while(left<right)
	{
		while(left<right&&arr[right]>pivot) --right;
		if(left<right)
			swap(left++,right);

		while(left<right&&arr[left]<=pivot) left++;
		if(left<right)
			swap(left,right--);

	}

	quick_sort(first,left-1);
	quick_sort(left+1,last);
}
void count_sort()
{
	int num[8]={0};
	for(size_t i=0;i<5;++i)
		num[arr[i]-1]++;
	for(size_t i=0,j=0;i<5,j<8;)
	{

		while(num[j]--){
			arr[i++]=j+1;
		}
		j++;
	}
}
int main()
{
	quick_sort(0,4);
	count_sort();
}

