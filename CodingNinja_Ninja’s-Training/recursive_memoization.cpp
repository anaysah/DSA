#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003

int f(int n, vector<vector<int>> &points, int r, int p, vector<vector<int>> &dp){
    if(r>=n) return 0;

    if(dp[r][p]!=-1) return dp[r][p];

    int i=0, ii=0, iii=0;

    if(p!=0 ){
        i = points[r][0] + f(n, points, r+1, 0, dp);
    }

    if(p!=1){
        ii = points[r][1] + f(n, points, r+1, 1, dp);
    }

    if(p!=2){
        iii = points[r][2] + f(n, points, r+1, 2, dp);
    }

    // cout<< dp[r]<< " ";
    return dp[r][p] = max(max(i, ii), iii);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    for(int c = 0; c < 3; c++){
        f(n, points, 0, c, dp);
    }
    return max(max(dp[0][0], dp[0][1]), dp[0][2]);
}

int main(){
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    cout<<ninjaTraining(3, points);

}