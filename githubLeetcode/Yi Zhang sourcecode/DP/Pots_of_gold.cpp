
#include "all.h"



//
//Pots of Gold	Nov. 9, 2007 9:30pm
//Category: Algorithms, Coding
//
//Question: Two players A and B are playing a game. Pots of gold, each with varying number of coins are placed in a single line.
//The rules of the game are:
//
//1) Players play turn by turn.
//2) On each turn a player can pick a pot of gold from either end of the line. He gets all the gold in that pot. The next pot of gold on that end is now available for picking.
//
//3) Players have full view of the pots i.e. they can see all the pots in the line and come up with a strategy.
//
//The goal of the game is to maximize the amount of gold for player A assuming that both players play optimally.
//





//Usually candidates start off with the greedy version. However, the example I have on the board usually makes it clear that greedy is not going to work
//
//After shooting down greedy, I look for a brute force solution first (2^N). Next I ask them to optimize it.
//If they get stuck I ask them to draw a tree of how the game would proceed. Good candidates would spot that many states are repeating and it is possible to optimize.
//Some candidates think of alpha-beta pruning.
//The solution which I am looking for is a O(N^2) dynamic programming.
//
//I ask them to code up either the recursive solution (and then memoize it) or the dynamic programming one if they get it.
//It is a little tricky as most candidates fail to optimize for both players.


//
//draw a tree of how the game would proceed.
//many states are repeating and it is possible to optimize.
//
//The solution which I am looking for is a O(N^2) dynamic programming.





//Hint on dynamic programming:
//Each pot of gold keeps the same neighbors throughout the game.
//So, if you start with 6 pots of gold (123456)
//then there are only 2 possibilities when there are 5 pots of gold 12345 or 23456,
//3 possibilities when there are 4 pots of gold 1234, 2345, 3456 and so forth.
//So for 6 pots of gold we have a total of 5+4+3+2+1 = 15 = 6C2 possibilites to consider in our dynamic programming.
//This is where the O(N^2) factor comes in.
//
//
//
//
//So for even number of pots, the problem is trivial and O(n).. Just sum up all pots that are sitting on even positions and all pots that are sitting on odd positions, see which sum is bigger and stick to those number, opponent will always have the other numbers to choose from.
//
//
//
//
//f(A, N) = max( A[0] + min(f(A+2, N-2), f(A+1, N-2)),
//              A[n-1] + min(f(A, N-2), f(A+1, N-2)) )
//
//
//A simpler recurrence :
//
//best(i,j) = max(value(i) - best(i+1, j), value(j) - best(i, j-1))
//
//
//
//case:
//10 5 15

//It's not a typical case of a minimax algorithm since you get the remainder of what's left by the previous pick.
//For one element, you get that value and remainder is 0.
//For two elements, you get the max and remainder is the min.
//For N elements, you get val = max(value(i) + best(i+1,j).remainder, value(j) + best(i, j-1).remainder), remainder is (sum of the subarray) - val.
//
//

//
//int maxGold(int* pots, int N) {
//    int values[N][N];
//    int remainder[N][N];
//    for (int i = N-1; i >= 0; --i) {
//        values[i][i] = pots[i];
//        remainder[i][i] = 0;
//        for (int j = i+1; j < N; ++j) {
//            values[i][j] = max(pots[i] + remainder[i+1][j],
//                               pots[j] + remainder[i][j-1]);
//            remainder[i][j] = arraySum(pots, i, j) - values[i][j]; // can be optimized
//        }
//    }
//    return values[0][N-1];
//}
//
//2. (25 points) Pots of Gold
//There are N pots of gold arranged linearly. Alice and Bob are playing the following game.
//They take alternate turns, and in each turn they remove (and win) either of the two pots at
//the two ends of the line.
//Alice plays ﬁrst. Given the amount of gold in each pot, design an algorithm to ﬁnd the maximum amount of gold
//that Alice can assure herself of winning.
//(a) (10 points) Clearly state the set of subproblems that you will use to solve this problem.
//(b) (10 points) Write a recurrence relating the solution of a general subproblem to solutions
//of smaller subproblems.
//(c) (5 points) Analyze the running time of your algorithm, including the number of subproblems and the
//time spent per subproblem. Hint: your overall algorithm should be
//O(N^2).
//

vector< vector<int> > best;
int getMax(int arr[],int beg,int end)
{
	if(beg>end){return 0;}
	if(beg==end){
		return arr[beg];
	}
	if(best[beg][end]!=0){
		return best[beg][end];
	}
    
	best[beg][end]=max(arr[beg]+min(getMax(arr,beg+2,end),getMax(arr,beg+1,end-1)) ,
                       arr[end]+min(getMax(arr,beg+1,end-1),getMax(arr,beg,end-2))
                       );
    
	return best[beg][end];
}
int pots_of_gold(int arr[],int n)
{
	best.assign(n+1, vector<int>(n+1,0));
	return getMax(arr,0,n-1);
}


int main()
{
	int arr[]={5,17,2,16,4,3,19,1};
	int arr2[]={5,10,15};
	int arr3[]={1,2,3,4,5,6};
	cout<<pots_of_gold(arr3,6)<<endl;
	return 0;
}
