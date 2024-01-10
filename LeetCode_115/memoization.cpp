#include <bits/stdc++.h>
using namespace std;
//DP 32. Distinct Subsequences | 1D Array Optimisation Technique

class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int a = 0;
        if(s[i]==t[j]){
            a = f(i+1, j+1, s, t, dp);
        }

        int b = f(i+1, j, s, t, dp);

        return dp[i][j] = a + b;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return f(0, 0, s, t, dp);
    }
};

int main() {

    return 0;
}