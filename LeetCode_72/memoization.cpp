#include <bits/stdc++.h>
using namespace std;
//DP 33. Edit Distance | Recursive to 1D Array Optimised Solution
//f1 and f2 are same but f1 is in forward direction and f2 is in backward direction


class Solution {
public:
    int f(int i, int j, string word1, string word2,int n, int m, vector<vector<int>>&dp){
        if(j>=m) return (n-i);
        if(i>=n) return (m-j);

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j] = f(i+1, j+1, word1, word2, n, m, dp);
        }else{
            int insert = 1 + f(i, j+1, word1, word2, n, m, dp);
            int del = 1 + f(i+1, j, word1, word2, n, m, dp);
            int replace = 1 + f(i+1, j+1, word1, word2, n, m, dp);

            return dp[i][j] = min(insert, min(del, replace));
        }
    }

    int f2(int i, int j, string word1, string word2, vector<vector<int>>&dp){
        if(j<0) return (i+1);
        if(i<0) return (j+1);

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j] = f(i-1, j-1, word1, word2, dp);
        }else{
            int insert = 1 + f(i, j-1, word1, word2, dp);
            int del = 1 + f(i-1, j, word1, word2, dp);
            int replace = 1 + f(i-1, j-1, word1, word2, dp);

            return dp[i][j] = min(insert, min(del, replace));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(0, 0, word1, word2, n, m, dp);
    }
};

int main() {

    return 0;
}