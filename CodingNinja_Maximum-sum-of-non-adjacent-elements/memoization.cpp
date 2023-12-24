#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
//dp 5 playlist striver 

int f(vector<int> &nums, int i, vector<int>&dp){
    if (i<0) return 0;
    if(i==0) return nums[i];

    if(dp[i]!=-1) return dp[i];

    int pick = nums[i] + f(nums, i-2, dp);
    
    int noPick = f(nums, i-1, dp);

    return dp[i] = max(pick, noPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int result =0;
    vector<int>dp(nums.size()+1, -1);
    return f(nums, nums.size()-1, dp);
}