#include <bits/stdc++.h>
using namespace std; 
//https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284
//DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach
//reffering to CodingNinja_Unbounded-Knapsack

int cutRod(vector<int> &price, int n)
{
	int w = n;
	vector<vector<int>> dp(n, vector<int>(w+1, 0));

    for(int c=1; c<=w; c++){
        dp[0][c] = (c/1)*price[0];
    }

    for(int r=1; r<n; r++){
        for(int c=1; c<=w; c++){
            int notPick = dp[r-1][c];

            int pick = 0;
            if(r+1<=c)
                pick = price[r] + dp[r][c-(r+1)];

            dp[r][c] = max(pick, notPick);
        }
    }

    return dp[n-1][w];
}