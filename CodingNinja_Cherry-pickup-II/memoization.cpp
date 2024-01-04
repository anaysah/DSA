#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885
//dp cherry pickup II / Choclate pickup
//striver DP 13. Cherry Pickup II | 3D DP Made Easy | DP On Grids

int f(int r, int Ac, int Bc, vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>> >&dp){
    if(r>=m) return 0;
    if(dp[r][Ac][Bc]!=-1) return dp[r][Ac][Bc];
    if(dp[r][Bc][Ac]!=-1) return dp[r][Bc][Ac];

    int l[] = {-1, 0, 1};
    int maxNo=0;
    for(int i=0; i<3; i++){
        if(Ac+l[i]>=n || Ac+l[i]<0) continue;
        for(int ii=0; ii<3; ii++){
            int AplusB = 0;

            if(Bc+l[ii]>=n || Bc+l[ii]<0){
                continue;
            }
            if(Ac==Bc) AplusB += grid[r][Ac];
            else{
                AplusB += grid[r][Ac];
                AplusB += grid[r][Bc];
            }
            AplusB += f(r+1, Ac+l[i], Bc+l[ii], grid, m, n, dp);

            maxNo = max(AplusB,maxNo);
        }
    }
    dp[r][Ac][Bc] = maxNo;
    dp[r][Bc][Ac] = maxNo;
    return maxNo;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>> > dp(r, vector<vector<int>>(c,vector<int>(c, -1)));
    return f(0,0, c-1, grid, r, c, dp);
}

int main(){
    vector<std::vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    // vector<std::vector<int>> matrix = {
    //     {1, 1},
    //     {1, 2}
    // };

    cout << maximumChocolates(matrix.size(), matrix[0].size(), matrix);
}