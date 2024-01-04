#include <bits/stdc++.h> 
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m=matrix.size(), n=matrix[0].size();

    for(int r=m-2; r>=0; r--){
        for(int c=n-1; c>=0; c--){
            int down=INT_MIN, downMinus=INT_MIN, downPlus=INT_MIN;

            if(r+1<m) down = matrix[r+1][c];
            if(r+1<m && c+1<n) downPlus = matrix[r+1][c+1];
            if(r+1<m && c-1>=0) downMinus = matrix[r+1][c-1];

            matrix[r][c] = matrix[r][c] + max(down,max(downPlus, downMinus));
        }
    }
    
    int mn = matrix[0][0];
    for(int i=0; i<n; i++){
        mn = max(matrix[0][i], mn);
    }
    return mn;
}