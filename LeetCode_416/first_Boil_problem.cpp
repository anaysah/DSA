#include <bits/stdc++.h>
using namespace std;
//this problem is same as Subset Sum Equal To K of coding ninja and you just have to reduce the problem
//striver DP 15. Partition Equal Subset Sum | DP on Subsequences

class Solution {
public:
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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2==0) sum = sum/2;
        else return false;
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return f(n, sum, nums, 0, dp);
    }
};