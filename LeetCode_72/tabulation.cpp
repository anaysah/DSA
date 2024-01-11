#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int r=0; r<=n; r++) dp[r][0] = r;
    for(int c=0; c<=m; c++) dp[0][c] = c;

    for(int r=1; r<=n; r++){
        for(int c=1; c<=m; c++){
            if(word1[r-1]==word2[c-1]){
                dp[r][c] = dp[r-1][c-1];
            }else{
                dp[r][c] = min(1 + dp[r-1][c], min(1+dp[r][c-1], 1+dp[r-1][c-1]));
            }
        }
    }
    return dp[n][m];
}

int main() {

    return 0;
}