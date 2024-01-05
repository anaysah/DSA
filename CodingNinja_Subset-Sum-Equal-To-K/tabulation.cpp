#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
//striver DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));
    for(int i=0;i<n;i++)dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int r=1; r<n; r++){
        for(int c=1; c<=k; c++){
            bool notTake = false;
            notTake = dp[r-1][c];
            bool take = false;
            if(arr[r]<=c) take = dp[r-1][c-arr[r]];
            dp[r][c] = (take || notTake);
        }
    }
    return dp[n-1][k];
}