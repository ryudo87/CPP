//odd number in first part,  even in second part
void adjust_array()
{
	int arr[]={3,2,0,4,2,7,9};
	int n=7;
	int i=0,j=6;
	while(i<j){
		while(i<n && arr[i]%2==1) i++;
		while(j>0 && arr[j]%2==0) j--;

		if(i<j){
			int t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
			i++;j--;
		}
	}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<","<<endl;
}