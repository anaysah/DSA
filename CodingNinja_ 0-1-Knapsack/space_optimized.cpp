#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
//DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>dp(maxWeight+1, 0);

	for(int c=weight[0]; c<=maxWeight; c++) {
		dp[c] = value[0];
	}

	for(int r=1; r<n; r++){
		for(int c=maxWeight; c>=1; c--){
			int take = 0;
			if(weight[r]<=c)
				take = value[r] + dp[c-weight[r]];
			
			int notTake = dp[c];
			dp[c] = max(take, notTake);
		}
	}

	return dp[maxWeight];
}