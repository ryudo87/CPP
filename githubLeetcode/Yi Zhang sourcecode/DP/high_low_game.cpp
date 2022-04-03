//Variation of High/Low Game 	May. 13, 2010 3:18pm
//Problem
//
//Think of a number from 1 to n (e.g., 1 to 100) and you have to guess it in a sequence of attempts. After each attempt, I either tell you if you are correct or direct you to guess "higher" or "lower". Your goal is to minimize the number of guesses.
//
//Now your goal is not to minimize the number of guesses, but rather to minimize the *sum* of guesses. Design, implement, and analyze the performance of a strategy to play this game optimally.
//
//[Candidate may ask whether the number is picked randomly or adversarially. The solution to the problem is similar for both cases, so it's up to the candidate. Default assumption should be that the number is picked adversarially, i.e., solution should be optimal in the worst case. See follow-up problem.]
// 
// Solution
// 
// Use dynamic programming / memoization. The key insight is that guessing X in the game (lo, hi) costs X and then results in one of three possibilities: game over, game (X+1, hi), or game (lo, X-1). We can thus compute the value of X that minimizes game(lo, hi) by iterating through all values of X and picking the one that minimizes X + max(game (X+1, hi), game (lo, X-1)).
// 
// Here is some sample code that assumes n = 100:
// 
// // Tables to store the costs and optimal guesses for game(i, j).
// int cost[101][101]; // worst-case cost of game (i, j)
// int guess[101][101]; // what to guess for game (i, j)
// 
// void InitializeTables() {
// for (int i = 1; i <= 100; i++)
// for (int j = i; j <= 100; j++)
// guess[i][j] = cost[i][j] = UNINITIALIZED;
// }
// 
// int ComputeCost(int lo, int hi) {
// // Stopping condition.
// if (lo > hi) return 0;
// 
// // Check if we have already computed result.
// if (cost[lo][hi] != UNINITIALIZED) return cost[lo][hi]
// 
// // Pick the guess that minimizes worst-case cost.
// int best_cost = INT_MAX;
// int best_guess = 0;
// for (int i = lo; i <= hi; i++) {
// int cost = i + max(ComputeCost(lo, i-1), ComputeCost(i+1,hi));
// if (cost < best_cost) {
// best_cost = cost;
// best_guess = i;
// }
// }
// 
// // Memoize the computation and return the result.
// cost[lo][hi] = best_cost;
// guess[lo][hi] = best_guess;
// return best_cost;
// }
// 
// 
// 
// // Play the game.
// void Play(int lo, int hi) {
// cost = ComputeCost(lo, hi);
// int current_guess = guess[lo, hi];
// cout << "Guess " << current_guess;
// if (CheckGuess(guess) == TOO_LOW) Play(current_guess + 1, hi);
// if (CheckGuess(guess) == TOO_HIGH) Play(lo, current_guess - 1);
// cout << "Done!";
// }
// 
// Analysis
// 
// Space requirement is O(n2), running time is O(n3).
// 
// 
// 
// 
// 
// 
// 
// Follow-On Question
// 
// If the candidate solves the adversarial case, then ask about the case where the number is chosen randomly and the goal is to minimize expected cost. Candidate should be able to make the adjustment to ComputeCost, i.e., 
// i + max(ComputeCost(lo, i-1), ComputeCost(i+1,hi)) 
// becomes i + (i - lo)/(hi - lo + 1) * ComputeCost(lo, i-1) + (hi - i) * ComputeCost(i+1, hi).
// 
 

#include "all.h"

#define Max 100
#define N 100
int cost[N+1][N+1];
int guess[N+1][N+1];

void init_table()
{
	for(int i=1;i<=100;i++)
		for(int j=i;j==100;j++)
			guess[i][j]=cost[i][i]=0;
}
int compute_cost(int low,int high)
{
	if(low>high) return 0;
	if(cost[low][high]!=0) return cost[low][high];

	int bestCost=Max;
	int bestGuess=0;

	for(int i=low;i<=high;++i)
	{
		int cost=i+max(compute_cost(low,i-1),compute_cost(i+1,high));
		if(cost<bestCost){
			bestCost=cost;
			bestGuess=i;
		}
	}

	cost[low][high]=bestCost;
	guess[low][high]=bestGuess;
	return bestCost;
}
int main()
{
	int low,high;
	cin>>low>>high;
	cout<<low<<endl;cout<<high<<endl;
	int cost=compute_cost(low,high);
	int myGuess=guess[low][high];
	cout<<"Guess:"<<myGuess<<" cost:"<<cost<<endl;

	return 1;
}
