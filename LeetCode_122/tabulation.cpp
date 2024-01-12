#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        for(int r=1; r<=n; r++){
            for(int c=1; c<3; c++){
                if(c==2){
                    dp[r][c] = max(-prices[n-r] + dp[r-1][1],
                    0 + dp[r-1][2]);
                }else{
                    dp[r][c] = max(prices[n-r] + dp[r-1][2],
                    0 + dp[r-1][1]);
                }
            }
        }

        return dp[n][2];
    }
};

int main() {

    return 0;
}