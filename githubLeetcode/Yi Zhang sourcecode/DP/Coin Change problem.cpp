#include "all.h"

//15. Coin Change problem.
//
//
//Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. We want to make changes with these coins for a given amount of money.
//
// For example, if we have 11 cents, then we can make changes with one 10-cent coin and one 1-cent coin, two 5-cent coins and one 1-cent coin, one 5-cent coin and six 1-cent coins, or eleven 1-cent coins. So there are four ways of making changes for 11 cents with the above coins. Note that we count that there is one way of making change for zero cent.
//
// Write a program to find the total number of different ways of making changes for any amount of money in cents. Your program should be able to handle up to 7489 cents.
//Input
//The input file contains any number of lines, each one consisting of a number for the amount of money in cents.
//Output
//For each input line, output a line containing the number of different ways of making changes with the above 5 types of coins.
//Sample Input
//
//11
//26
//Sample Output
//4
//13
//
//
int record[5][100];
int coinSet[]={1,5,10,25,50};
int coin_change(int n,int curMinIndex, vector<int>& resSet)
{
	int result=0;
	for(unsigned i=curMinIndex;i<sizeof(coinSet)/sizeof(coinSet[0]);++i){
		if(n-coinSet[i]==0) {
			resSet.push_back(coinSet[i]);
			cout<<"result:";
			for(unsigned i=0;i<resSet.size();++i){cout<<resSet[i]<<",";}cout<<endl;
			resSet.pop_back();
			result++;
			break;
		}
		if(n-coinSet[i]>= coinSet[i] ){
			if(  record[i][n-coinSet[i]]==0){
				resSet.push_back(coinSet[i]);
				record[i][n-coinSet[i]]=coin_change(n-coinSet[i],i, resSet);
				resSet.pop_back();
			}
			result+=record[i][n-coinSet[i]];
		}

		else break;
	}

	return result;

}

int main()
{
	int n;
	cin>>n;
	vector<int> resSet;


	cout<<coin_change(n,0,resSet);
	return 0;
}

