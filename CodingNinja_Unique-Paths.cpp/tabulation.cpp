#include <bits/stdc++.h>
using namespace std;

int f(int m, int n, int c_m, int c_n, vector<vector<int>>&dp){
    if(c_m==(m) && c_n==(n)){
        return 1;
    }
    if(dp[c_m][c_n]!=0)return dp[c_m][c_n];

    int right=0, down=0;

    if(c_n+1<=n)
    right = f(m, n, c_m, c_n+1, dp);
    
    if(c_m+1<=m)
    down = f(m, n, c_m+1, c_n, dp);

    dp[c_m][c_n] = right + down;
    return dp[c_m][c_n];
}

int uniquePaths(int m, int n) {
    vector<vector<int> >dp(m+1, vector<int>(n+1, 0));
    dp[m][n] = 1;
    for(int r=m; r>0; r--){
        for(int c=n; c>0; c--){
            int right = 0, down = 0;

            if(r==m && c==n) continue;

            if(r+1<=m) right = dp[r+1][c];
            if(c+1<=n) down = dp[r][c+1];

            dp[r][c] = right + down;
        }
    }

    return dp[1][1];
}

int main(){
    cout<<"done: "<<uniquePaths(3, 3)<<" ans";
}