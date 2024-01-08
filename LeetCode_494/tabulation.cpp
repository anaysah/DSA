#include <bits/stdc++.h> 
using namespace std;
//Leetcode 494 DP 21. Target Sum | DP on Subsequences
//reffering to DP 18 and CodingNinja_Partitions-With-Given-Difference

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int sum = 0;
        for(int i=0; i<m; i++) sum+=nums[i];

        if(sum-target<0 || (sum-target)%2!=0)return 0;
        int newTarget = (sum-target)/2;

        vector<vector<int>>dp(m, vector<int>(newTarget+1, 0));
        // for(int r=0; r<m; r++) dp[r][0] = 0;
        dp[0][0] += 1;
	    if(nums[0]<=newTarget)dp[0][nums[0]] += 1;

        for(int r=1; r<m; r++){
            for(int c=newTarget; c>=0; c--){
                int take = 0;
                if(nums[r] <= c) take = dp[r-1][c-nums[r]];
                dp[r][c] = (dp[r-1][c] + take);
            }
	    }


        return dp[m-1][newTarget];
    }
};