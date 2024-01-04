#include <bits/stdc++.h>
using namespace std;
//www.codingninjas.com/studio/problems/maze-obstacles_977241
//dp problem

const int MOD = 1000000007;

int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    if (mat[m-1][n-1] == -1) return 0;
    mat[m-1][n-1] = 1;
    mat[0][0] = 0;
    for(int r=m-1; r>=0; r--){
        for(int c=n-1; c>=0; c--){
            if(r==m-1 && c==n-1) continue;
            if(mat[r][c]==-1) continue;
            int right = 0,down = 0;

            if(r+1<m && mat[r+1][c]!=-1) down = mat[r+1][c];
            if(c+1<n && mat[r][c+1]!=-1) right = mat[r][c+1];

            mat[r][c] = (right+down) % MOD;
        }
    }

    return mat[0][0];
}
int main(){
    vector<std::vector<int>> dp = {
        {0, -1, 0, 0, -1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, -1, -1, 0, 0},
        {0, 0, 0, -1, -1, 0, 0, 0, 0},
        {-1, 0, 0, 0, 0, 0, 0, 0, 0},
        {-1, 0, 0, 0, 0, 0, -1, -1, 0}
    };

    cout<<"start: "<<mazeObstacles(5,9, dp)<<" end";
}