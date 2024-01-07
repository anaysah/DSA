#include <bits/stdc++.h> 
using namespace std;
//https://leetcode.com/problems/coin-change/submissions/1139242375/
//DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern

void printVector(vector<int> v)
{
    cout<<"[ ";
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]!=INT_MAX)
        cout << v[i] << " ";
        else cout << "M" << " ";
    }
    cout<<"]";
    cout << endl;
}

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        vector<vector<int>> dp(m, vector<int>(amount+1, 0));

        for(int r=0; r<m; r++) dp[r][0] = 0;
        for(int c=1; c<=amount; c++){
            if((c%coins[0])==0) dp[0][c] = c/coins[0];
            else dp[0][c] = INT_MAX;
        }

        for(int r=1; r<m; r++){
            for(int c=1; c<=amount; c++){
                printVector(dp[0]);
                printVector(dp[r]);
                cout<<endl;
                int notTake = dp[r-1][c];
                int take;
                if((c-coins[r])<0 || dp[r][c-coins[r]]==INT_MAX) take = INT_MAX;
                else take = 1 + dp[r][c-coins[r]];
                dp[r][c] = min(take, notTake);
            }
        }

        int v= dp[m-1][amount];
        if(v==INT_MAX) return -1;
        return v;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1};
    cout<< s.coinChange(nums, 5)<<endl;
}