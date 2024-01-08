#include <bits/stdc++.h>
using namespace std;
//Dp 25. Longest Common Subsequence | Top Down | Bottom-Up | Space Optimised | DP on Strings


int f(int i, int j, string text1, string text2, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(text1[i]==text2[j])
        ans =  1 + f(i-1, j-1, text1, text2, dp);
    else{
        ans = max(f(i-1, j, text1, text2, dp) , f(i, j-1, text1, text2, dp));
    }
    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
    int i=text1.size()-1;
    int j=text2.size()-1;
    vector<vector<int>> dp(i+1, vector<int>(j+1,-1));
    return f(i, j, text1, text2, dp);
}