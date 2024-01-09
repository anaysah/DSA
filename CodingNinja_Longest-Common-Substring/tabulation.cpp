#include <bits/stdc++.h>
using namespace std;
//DP 27. Longest Common Substring | DP on Strings
//https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

int lcs(string &text1, string &text2){
    int i=text1.size();
    int j=text2.size();
    vector<vector<int>> dp(i+1, vector<int>(j+1,0));

    int m = 0;
    for(int r=1; r<=i; r++){
        for(int c=1; c<=j; c++){
            if(text1[r-1]==text2[c-1]){
                dp[r][c] = 1 + dp[r-1][c-1];
                m = max(m, dp[r][c]);
            }
        }
    }
    return m;
}