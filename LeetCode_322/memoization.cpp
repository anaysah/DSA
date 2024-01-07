#include <bits/stdc++.h> 
using namespace std;
//https://leetcode.com/problems/coin-change/submissions/1139242375/
//DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern

class Solution {
public:
    int f(vector<int>& coins, int amount, int i, int n, vector<vector<int>> &dp){
        if(i>=n) return INT_MAX;
        if(amount<=0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take = INT_MAX;
        if(coins[i]<=amount){
            take = f(coins,amount-coins[i], i, n, dp);
        }
        if(take!=INT_MAX) take += 1;

        int notTake = f(coins, amount, i+1, n, dp);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int v= f(coins, amount, 0, coins.size(), dp);
        if(v==INT_MAX) return -1;
        return v;
    }
};