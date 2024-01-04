#include <bits/stdc++.h> 
using namespace std;
//Minimum Path Sum
//https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
//dp problem

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    for(int r=m-1; r>=0; r--){
        for(int c=n-1; c>=0; c--){
            if(r==m-1 && c==n-1) continue;
            int right=INT_MAX , down=INT_MAX;

            if(r+1<m) down = grid[r+1][c];
            if(c+1<n) right = grid[r][c+1];

            grid[r][c] = grid[r][c] + min(down, right);
        }
    }
    return grid[0][0];
}