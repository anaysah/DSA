#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    dp[n-1][0] = points[n-1][0];
    dp[n-1][1] = points[n-1][1];
    dp[n-1][2] = points[n-1][2];
    
    for(int r=n-2; r>=0; r--){
        for(int c=0; c<3; c++){
            int i=0, ii=0, iii=0;

            if(c!=0)
                i = points[r][c] + dp[r+1][0];

            if(c!=1)
                ii = points[r][c] + dp[r+1][1];

            if(c!=2)
                iii = points[r][c] + dp[r+1][2];

            dp[r][c] = max(max(i, ii), iii);
        }
    }

    return max(max(dp[0][0], dp[0][1]), dp[0][2]);
}

int main(){
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    cout<<ninjaTraining(points.size(), points);

}