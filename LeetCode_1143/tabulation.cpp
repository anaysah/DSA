#include <bits/stdc++.h>
using namespace std;
//Dp 25. Longest Common Subsequence | Top Down | Bottom-Up | Space Optimised | DP on Strings

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size();
        int j=text2.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1,0));

        for(int r=1; r<=i; r++){
            for(int c=1; c<=j; c++){
                if(text1[r-1]==text2[c-1]){
                    dp[r][c] = 1 + dp[r-1][c-1];
                }
                else{
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[i][j];
    }
};