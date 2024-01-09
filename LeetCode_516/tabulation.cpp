#include <bits/stdc++.h>
using namespace std;
//DP 28. Longest Palindromic Subsequence
// reffering to LeetCode_1143 ans just give the same string s as text2 in reverse order

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i = s.size();
        vector<vector<int>> dp(i+1, vector<int>(i+1, 0));

        for(int r=1; r<=i; r++){
            for(int c=1; c<=i; c++){
                if(s[c-1]==s[i-r]){
                    dp[r][c] = 1 + dp[r-1][c-1];
                }else{
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[i][i];
    }
};