#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
//dp 5 playlist striver 

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int>dp(nums.size()+1, -1);
    dp[0] = nums[0];

    for(int i=1; i<nums.size(); i++){
        int pick = nums[i] + ((i>1)?dp[i-2]:0);
        int noPick = dp[i-1];
        dp[i] = max(pick, noPick);
    }
    return dp[nums.size()-1];
}