#include "all.h"

//Find Maximum money you can make by making at most N transactions
//DISCLAIMER: The N = 1 portion of this question is not my idea and could already be here.

//
//Lets say you are given a stream of quotes for a stock from the last trading day. Assume its already time sorted. Find the maximum amount of money you could have made on this stock by making at most N transactions. A buy and a sell is counted as one transaction. Four parts N = 1, N = 2 and N = Inf and the generic solution for N = some number (open ended)
//
//Example:
//
//time Price
//1 10
//2 11
//3 7
//4 15
//5 8
//6 17
//7 16

//for N=1 answer is 10 buy at 3 and sell at 6
//for N=2 answer is 8 + 9 buy at 3, sell at 4, buy at 5, sell at 6.
//for N=Inf, answer is buy and sell anytime stock price dips (This is also the solution)
//
//Pretty easy to get O(N) solution for N = 1, getting a O(N) solution for N=2 is a little tricky, but it is just an extension of N=1, so it should not be hard to provide some pretty good hints without giving away the solution. For those of you who are too lazy to work it out, solution is to make two passes, from left to right and then from right to left.
//
//I have not been able to get anything concrete on getting a generic solution. I have only been able to come up with some ideas based on dynamic programming. Let me know if anyone has a better idea.
//
//I have never asked this question, so plan to do pretty soon as long as I don't get overwhelmingly negative comments here, but these are my expectations.
//
//N = 1 and N = Inf are really easy and any candidate should be able to get it quickly. No excuses.
//N = 2 is a little tricky and a good candidate should be able to get it and code it up within an interview.
//If the candidate is really good, then he should complete all of the above and provide some good insights for the generic solution.
//


//O(n)
int make_Maximum_money_at2transactions(int arr[],int n)
{
	vector<int> trough,peak,l2rDiff,r2lDiff;bool up=false;

	for(int i=1;i<n;++i){
		if(arr[i]>arr[i-1]){
			if(!up){
				up=true;
				trough.push_back(arr[i-1]);//push
			}
		}
		else{//down
			if(up){
				up=false;
				peak.push_back(arr[i-1]);
			}
		}
	}
	if(up){
		peak.push_back(arr[n-1]);
	}

	int tmin=INT_MAX,tmax=INT_MIN,diff=0,k=peak.size();
	for(int i=0;i<k;++i){
		if(trough[i]<tmin){
			tmin=trough[i];
		}
		if(peak[i]-tmin>diff){
			diff=peak[i]-tmin;
		}
		l2rDiff.push_back(diff);
	}

	diff=0;
	for(int i=k-1;i>=0;--i){
		if(peak[i]>tmax){
			tmax=peak[i];
		}
		if(tmax-trough[i]>diff){
			diff=tmax-trough[i];
		}
		r2lDiff.push_back(diff);
	}


	tmax=0;
	for(int j=0;j<k-1;++j){
		if(l2rDiff[j]+r2lDiff[k-2-j]>tmax){
			tmax=l2rDiff[j]+r2lDiff[k-2-j];
		}
	}
	return tmax;
}


//my top down method   O(n^2)
void get_peak_and_trough(vector<int>& trough,vector<int>& peak,int arr[],int n)
{	bool up=false;
	for(int i=1;i<n;++i){
		if(arr[i]>arr[i-1]){
			if(!up){
				up=true;
				trough.push_back(arr[i-1]);//push
			}
		}
		else{//down
			if(up){
				up=false;
				peak.push_back(arr[i-1]);
			}
		}
	}
	if(up){
		peak.push_back(arr[n-1]);
	}
}


int maximize1transaction(vector<int>& trough,vector<int>& peak,int beg,int end)
{
	if(beg>end) return 0;
	int maxdiff=INT_MIN, curmin=INT_MAX;
	for(int i=beg;i<=end;++i){
		if(trough[i]<curmin){
			curmin=trough[i];
		}
		//if(peak[i]-curmin>maxdiff)
		{
			maxdiff=(peak[i]-curmin>maxdiff) ? (peak[i]-curmin) :maxdiff;
		}
	}
	return maxdiff;
}
int	make_max_money(int arr[],int n)
{
	vector<int> trough;
	vector<int> peak;
	get_peak_and_trough(trough,peak,arr,n);

	int sum=maximize1transaction(trough,peak,0,peak.size()-1);
	//make 2 transaction
	for(int i=0;i<peak.size()-1;++i){
		int t=maximize1transaction(trough,peak,0,i)+maximize1transaction(trough,peak,i+1,peak.size()-1);
		if(t>sum)
		{
			sum=t;
		}
	}
	return sum;
}
int main()
{
	//int arr[]={10,11,7,15,8,17,16};
	int arr[]={3, 6, 8, 5, 7, 9, 13, 15, 10, 6, 2, 7, 11, 8, 6 };
	cout<<make_Maximum_money_at2transactions(arr,sizeof(arr)/sizeof(arr[0]))<<endl;//exact 2 transactions

	cout<<make_max_money(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
	return 0;
}


