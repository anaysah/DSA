#include <bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int recursion(int n, vector<int>&h, vector<int>&dp){
    if (n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int left = recursion(n-1, h, dp) + abs(h[n]- h[n-1]);

    int right = INT_MAX;
    if(n>1) 
    right = recursion(n-2, h, dp) + abs(h[n]- h[n-2]);

    dp[n] = min(left, right);

    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return recursion(n-1, heights, dp);
}