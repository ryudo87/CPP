#include "all.h"

//Find Maximum money you can make by making at most N transactions	Jan. 5, 2011 2:38am
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
//你哈
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

//ÊàëËßâÂæóÁ¨¨‰∫åÈ¢òÊòØÂèØ‰ª•O(n)ÁöÑ
//
//ÂèØ‰ª•ÊääÂéüÊï∞ÁªÑÁöÑÊâÄÊúâÊ≥¢Â≥∞Ê≥¢Ë∞∑ÂàÜÂà´ËÆ∞ÂΩïÂà∞‰∏§‰∏™Êï∞ÁªÑa[k],b[k]‰∏≠Ôºå
//È¢òÁõÆÁõ∏ÂΩì‰∫éÊòØÂú®ÊääÊï∞ÁªÑaÔºåbÂàÜÊàê‰∏§ÊÆµ‰ΩøÂæó‰∏§ÊÆµ‰∏≠ÁöÑaÔºåbÂ∑ÆÂÄºÂíå
//‰∏∫ÊúÄÂ§ß„ÄÇ
//
//ÂèØ‰ª•ÂÖà‰ªéÂâçÂêëÂêéÊâ´ÊèèÊï∞ÁªÑaÔºåbÔºåÂØπ‰∫éÊâÄÊúâindex i,ËÆ°ÁÆó b[q]-a[p]
//ÁöÑÊúÄÂ§ßÂÄºÔºåÂ≠òÂú®c[i]‰∏≠ÔºåÂÖ∂‰∏≠ 0<= p <= q <=iÔºõ
//ÁÑ∂Âêé‰ªéÂêéÂêëÂâçÊâ´ÊèèÊï∞ÁªÑaÔºåbÔºåÂØπ‰∫éÊâÄÊúâindex iÔºåËÆ°ÁÆó b[q]-a[p]
//ÁöÑÊúÄÂ§ßÂÄºÔºåÂ≠òÂú®d[i]‰∏≠ÔºåÂÖ∂‰∏≠ i<= p <= q <=k-1
//
//ÁÑ∂ÂêéËÆ°ÁÆóindex j‰ΩøÂæóc[j]+d[k-1-j]ÊúÄÂ§ßÔºå 0<= j<= k-1
//
//‰ªéÂâçÂêëÂêéÊâ´Êèè‰∏ÄÈÅçÔºåÁîüÊàêÊï∞ÁªÑc[]„ÄÇÂü∫Êú¨‰∏äÂ∞±ÊòØËÆ∞ÂΩïÂΩìÂâçÈÅáÂà∞ËøáÁöÑÊúÄÂ∞èaÂÄºÔºå
//ÁÑ∂ÂêéÂØπÊØè‰∏™b[i]ÁÆóÂ∑ÆÂÄº,Â≠òÂà∞c[i]‰∏≠„ÄÇÂàó‰∏Ä‰∏ã‰º™‰ª£Á†ÅÂèØËÉΩÊ∏ÖÊ•ö‰∏ÄÁÇπÔºåÁîüÊàê
//Êï∞ÁªÑdÁöÑËøáÁ®ãÁ±ª‰ºº„ÄÇ


int make_Maximum_money_at2transactions(int arr[],int n)
{
	vector<int> trough,peak,l2rDiff,r2lDiff;bool up=false;

//	ÂèØ‰ª•ÊääÂéüÊï∞ÁªÑÁöÑÊâÄÊúâÊ≥¢Â≥∞Ê≥¢Ë∞∑ÂàÜÂà´ËÆ∞ÂΩïÂà∞‰∏§‰∏™Êï∞ÁªÑtrough[k],peak[k]‰∏≠Ôºå
//	È¢òÁõÆÁõ∏ÂΩì‰∫éÊòØÂú®ÊääÊï∞ÁªÑaÔºåbÂàÜÊàê‰∏§ÊÆµ‰ΩøÂæó‰∏§ÊÆµ‰∏≠ÁöÑaÔºåbÂ∑ÆÂÄºÂíå
//	‰∏∫ÊúÄÂ§ß„ÄÇ

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


//	ÂèØ‰ª•ÂÖà‰ªéÂâçÂêëÂêéÊâ´ÊèèÊï∞ÁªÑaÔºåbÔºåÂØπ‰∫éÊâÄÊúâindex i,ËÆ°ÁÆó b[q]-a[p]
//	ÁöÑÊúÄÂ§ßÂÄºÔºåÂ≠òÂú®c[i]‰∏≠ÔºåÂÖ∂‰∏≠ 0<= p <= q <=iÔºõ
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

//	ÁÑ∂Âêé‰ªéÂêéÂêëÂâçÊâ´ÊèèÊï∞ÁªÑaÔºåbÔºåÂØπ‰∫éÊâÄÊúâindex iÔºåËÆ°ÁÆó b[q]-a[p]
//	ÁöÑÊúÄÂ§ßÂÄºÔºåÂ≠òÂú®d[i]‰∏≠ÔºåÂÖ∂‰∏≠ i<= p <= q <=k-1

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

	//ÁÑ∂ÂêéËÆ°ÁÆóindex j‰ΩøÂæóc[j]+d[k-2-j]ÊúÄÂ§ßÔºå 0<= j<= k-1
	tmax=0;
	for(int j=0;j<k-1;++j){
		if(l2rDiff[j]+r2lDiff[k-2-j]>tmax){
			tmax=l2rDiff[j]+r2lDiff[k-2-j];
		}
	}
	return tmax;
}

int main()
{
	//int arr[]={10,11,7,15,8,17,16};
	int arr[]={3, 6, 8, 5, 7, 9, 13, 15, 10, 6, 2, 7, 11, 8, 6 };
	cout<<make_Maximum_money_at2transactions(arr,sizeof(arr)/sizeof(arr[0]))<<endl;

	return 0;
}


