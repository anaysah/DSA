#include <bits/stdc++.h>
using namespace std;
//DP 32. Distinct Subsequences | 1D Array Optimisation Technique

class Solution {
public:
    int numDistinct(string s, string t) {
        int i = s.size(), j= t.size();
        vector<vector<unsigned long>> dp(i + 1, vector<unsigned long>(j + 1,0));

        for(int r=0; r<=i; r++){
            dp[r][0] =1;
        }

        for(int r=1; r<=i; r++){
            for(int c=1; c<=j; c++){
                unsigned long a = 0;
                if(s[r-1]==t[c-1]){
                    a = dp[r-1][c-1];
                }
                unsigned long b = dp[r-1][c];
                dp[r][c] = a + b;
            }
        }

        return dp[i][j];
    }
};

int main() {

    return 0;
}