#include <bits/stdc++.h>
using namespace std;
//DP 35. Best Time to Buy and Sell Stock | DP on Stocks
//https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_893405

int maximumProfit(vector<int> &prices){
    int result =0;
    int mn = prices[0], mx = prices[0];

    for(int i=0; i<prices.size(); i++){
        if(prices[i]<mn){
            result = max(result, mx-mn);
            mn = prices[i];
            mx = prices[i];
        }else{
            mx = max(prices[i], mx);
        }
    }
    return result = max(result,mx-mn);
}

int main() {

    return 0;
}