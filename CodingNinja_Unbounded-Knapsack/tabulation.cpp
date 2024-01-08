#include <bits/stdc++.h>
using namespace std; 
//https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029
//DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));

    for(int c=0; c<=w; c++){
        dp[0][c] = (c/weight[0])*profit[0];
    }

    for(int r=1; r<n; r++){
        for(int c=1; c<=w; c++){
            int notPick = dp[r-1][c];

            int pick = 0;
            if(weight[r]<=c) 
                pick = profit[r] + dp[r][c-weight[r]];

            dp[r][c] = max(pick, notPick);
        }
    }

    return dp[n-1][w];
}