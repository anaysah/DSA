#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(-prices[i] + f(i+1, 0, prices, dp), 
            0 + f(i+1, 1, prices, dp));
        }else{
            return dp[i][buy] = max(prices[i]+f(i+1, 1, prices, dp),
            0 + f(i+1, 0, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

int main() {

    return 0;
}