#include <bits/stdc++.h>
using namespace std; 
//https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029
//DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach

int f(int n, int w, vector<int> &profit, vector<int> &weight, int i, vector<vector<int>>&dp){
    if(i>=n) return 0;
    if(w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

    int pick = 0;
    if(weight[i]<=w){
        pick = profit[i] + f(n, w-weight[i], profit, weight, i, dp);
    }

    int notPick = f(n, w, profit, weight, i+1, dp);

    return dp[i][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));

    return f(n, w, profit, weight, 0, dp);
}