#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
//DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences

int f(vector<int> weight, vector<int> value, int n, int maxWeight, int i, vector<vector<int>>&dp){
	if(i>=n) return 0;
	if(maxWeight<=0) return 0;
	if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];

	int take=0;
	if(maxWeight-weight[i]>=0)
		take = value[i] + f(weight, value, n, maxWeight-weight[i], i+1, dp);

	int notPick = f(weight, value, n, maxWeight, i+1, dp);

	return dp[i][maxWeight] = max(take, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1, -1));
	return f(weight, value, n, maxWeight, 0, dp);
}