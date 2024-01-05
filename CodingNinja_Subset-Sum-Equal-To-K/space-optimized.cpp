#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
//striver DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> dp(k+1, false), temp(k+1, false);
    
    dp[0] = temp[0] =true;
    dp[arr[0]] = true;
    for(int r=1; r<n; r++){
        for(int c=1; c<=k; c++){
            // bool notTake = false;
            bool notTake = dp[c];
            bool take = false;
            if(arr[r]<=c) take = dp[c-arr[r]];
            temp[c] = (take || notTake);
        }
        dp = temp;
    }
    return dp[k];
}