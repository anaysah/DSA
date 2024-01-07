#include <bits/stdc++.h> 
using namespace std;
//https://leetcode.com/problems/coin-change/submissions/1139242375/
//DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern

int f(vector<int>& coins, int amount, int i, int n){
        if(i>=n) return INT_MAX;
        if(amount<=0) return 0;

        int take = INT_MAX;
        if(coins[i]<=amount){
            take = f(coins,amount-coins[i], i, n);
        }
        if(take!=INT_MAX) take += 1;

        int notTake = f(coins, amount, i+1, n);

        return min(take, notTake);
    }

int minimumElements(vector<int> &num, int x)
{
    int v= f(num, x, 0, num.size());
    if(v==INT_MAX) return -1;
    return v;
}