#include <bits/stdc++.h> 
using namespace std;
//DP 22. Coin Change 2 | Infinite Supply Problems | DP on Subsequences

class Solution {
public:
    int f(int amount, vector<int>& coins, int i, vector<vector<int>> &dp){
        if(i>=coins.size()) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int pick =0;
        if(coins[i]<=amount)
            pick = f(amount-coins[i], coins, i, dp);
        
        int notPick = f(amount, coins, i+1, dp);

        return dp[i][amount] = pick+notPick;
    }

    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        vector<vector<int>> dp(m, vector<int>(amount+1,-1));
        return f(amount, coins, 0, dp);
    }
};