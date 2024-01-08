#include <bits/stdc++.h> 
using namespace std;
//DP 22. Coin Change 2 | Infinite Supply Problems | DP on Subsequences

class Solution {
public:
    int f(int amount, vector<int>& coins, int i){
        if(i>=coins.size()) return 0;
        if(amount==0) return 1;

        int pick =0;
        if(coins[i]<=amount)
            pick = f(amount-coins[i], coins, i);
        
        int notPick = f(amount, coins, i+1);

        return pick+notPick;
    }

    int change(int amount, vector<int>& coins) {
        // int m = coins.size();
        return f(amount, coins, 0);
    }
};