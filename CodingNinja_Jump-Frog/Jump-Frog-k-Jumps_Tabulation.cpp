#include <bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int frogJump(int n, vector<int> &heights, int k){
    if (n==0) return 0;
    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for(int i=1;i<n;i++){
        int m = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>-1){
                int jump = dp[i-j] + abs(heights[i]-heights[i-j]);
                m = min(m, jump);
            }
        }
        dp[i] = m;
    }
    return dp[n-1];
    
}

int main(){
    vector<int>h1 = {10, 30, 40, 50, 20}; //30 output
    cout <<frogJump(5, h1, 3)<<endl;
    vector<int>h2 = {10, 20, 10};    //20output
    cout <<frogJump(3, h2, 1)<<endl;

    vector<int>h3 = {10, 10}; //0 output
    cout <<frogJump(2, h3, 100)<<endl;

    vector<int>h4 = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60}; //40 output
    cout <<frogJump(10, h4, 4)<<endl;
}