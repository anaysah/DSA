#include <bits/stdc++.h>
using namespace std;
//DP 30. Minimum Insertions/Deletions to Convert String A to String B
// refering to LeetCode 516

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.size(), j = word2.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1, 0));

        for(int r=1; r<=i; r++){
            for(int c=1; c<=j; c++){
                if(word1[r-1]==word2[c-1]){
                    dp[r][c] = 1 + dp[r-1][c-1];
                }else{
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }

        return (i - dp[i][j]) + (j - dp[i][j]);
    }
};