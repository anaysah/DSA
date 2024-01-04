#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int>dp(n+1);
    dp[n] = 1;
    int cnext = 1;
    for(int r=m; r>0; r--){
        for(int c=n; c>0; c--){
            int right = 0, down = 0;

            if(r==m && c==n) continue;

            if(r+1<=m) down = dp[c];
            if(c+1<=n) right = cnext;

            cnext = right + down;
            dp[c] = cnext;
        }
    }

    return dp[1];
}

int main(){
    cout<<"done: "<<uniquePaths(3, 4)<<" ans";
}