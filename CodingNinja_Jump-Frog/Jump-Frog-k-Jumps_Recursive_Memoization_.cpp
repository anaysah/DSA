#include <bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int recursion(int n, vector<int>&h, vector<int>&dp, int k){
    if (n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int m = INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>-1){
            int jump = recursion(n-i, h, dp, k) + abs(h[n]- h[n-i]);
            m = min(m, jump);
        }
    }

    // int left = recursion(n-1, h, dp) + abs(h[n]- h[n-1]);

    // int right = INT_MAX;
    // if(n>1) 
    // right = recursion(n-2, h, dp) + abs(h[n]- h[n-2]);

    dp[n] = m;

    return dp[n];
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n+1, -1);
    return recursion(n-1, heights, dp, k);
}

int main(){
    // vector<int>heights = {10, 30, 40, 50, 20}; //30 output
    // cout <<frogJump(5, heights, 3)<<endl;
    // vector<int>heights = {10, 20, 10};    //20output
    // cout <<frogJump(3, heights, 1)<<endl;

    // vector<int>heights = {10, 10}; //0 output
    // cout <<frogJump(2, heights, 100)<<endl;

    // vector<int>heights = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60}; //40 output
    // cout <<frogJump(10, heights, 4)<<endl;
}