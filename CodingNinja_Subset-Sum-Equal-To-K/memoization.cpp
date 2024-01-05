#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
//striver DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them

bool f(int n, int target, vector<int> &arr, int i, vector<vector<int>>&dp){
    // if(target==arr[i]) return true;
    if(i>=n || target<0) return false;
    if(dp[i][target]!=-1)return dp[i][target];
    if(target-arr[i]==0) return true;

    bool pick = f(n, target-arr[i], arr, i+1, dp);
    if(pick) return true;

    bool notPick = f(n, target, arr, i+1, dp);

    return dp[i][target] = (notPick)?1:0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n, k, arr, 0, dp);
}