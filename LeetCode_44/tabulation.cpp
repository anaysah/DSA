#include <bits/stdc++.h>
using namespace std;
//DP 34. Wildcard Matching | Recursive to 1D Array Optimisation

//test case s = "" , p = "****"

class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(j>=p.size() && i>=s.size()) return true; //agar i aur j dono size se bade ho jaye
        if(i<s.size() && j>=p.size()) return false; //agar j khatam ho jaye par i khatam na ho

        if(i>=s.size() && j<p.size()){              // agar i khatam ho jaye par j nahi
            for(int k=j; k<p.size(); k++){
                // ab jab sirf j bacha hai toh ham sirf * ke liye check karenge
                //uske alava kuch bhi aaya toh matlb nahi hoga answer
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || (p[j]=='?')){
            return dp[i][j] = f(i+1, j+1, s, p, dp);
        }
        if(p[j]=='*'){
            return dp[i][j] = (f(i+1, j, s, p, dp) || f(i, j+1, s, p, dp));
        }
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(0, 0, s, p, dp);
    }
};

int main() {

    return 0;
}