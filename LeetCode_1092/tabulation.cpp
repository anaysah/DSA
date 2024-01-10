#include <bits/stdc++.h>
using namespace std;
//DP 31. Shortest Common Supersequence | DP on Strings

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i = str1.size(), j = str2.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1, 0));

        for(int r=1; r<=i; r++){
            for(int c=1; c<=j; c++){
                if(str1[r-1]==str2[c-1]){
                    dp[r][c] = 1 + dp[r-1][c-1];
                }else{
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }

        int size = dp[i][j] + (i-dp[i][j]) + (j-dp[i][j]);

        string s(size, ' ');

        int r=i, c=j;
        int p = size-1;
        while(r>0 && c>0){
            if(str1[r-1]==str2[c-1]){
                s[p] = str1[r-1];
                r--; c--;p--;
            }else if(dp[r-1][c]>dp[r][c-1]){
                s[p] = str1[r-1];
                r--;p--;
            }else{
                s[p] = str2[c-1];
                c--;p--;
            }
            
        }
        while(c>0){
            s[p] = str2[c-1];
            p--;c--;
        }
        while(r>0){
            s[p] = str1[r-1];
            p--;r--;
        }
        
        return s;
    }
};

int main() {

    return 0;
}