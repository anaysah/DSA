#include <bits/stdc++.h> 
using namespace std;
//DP 22. Coin Change 2 | Infinite Supply Problems | DP on Subsequences

void printVector(vector<int> v)
{
    cout<<"[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<"]";
    cout << endl;
}

int change(int amount, vector<int>& coins) {
    int m = coins.size();
    vector<vector<int>> dp(m, vector<int>(amount+1,0));

    for(int c=0; c<=amount; c++){
        if(c%coins[0]==0) dp[0][c] = 1;
    }
    for(int r=0; r<m; r++){
        dp[r][0] = 1;
    }

    for(int r=1; r<m; r++){
        for(int c=1; c<=amount; c++){
            int pick =0;
            if (coins[r]<=c)
                pick = dp[r][c-coins[r]];
            
            int notPick = dp[r-1][c];
            dp[r][c] = pick + notPick;
        }
    }


    return dp[m-1][amount];
}

int main(){
    vector<int>coins = {2,1,5};
    cout<<change(5, coins)<<"ans";
}