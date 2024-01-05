#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
//striver DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them

bool f(int n, int target, vector<int> &arr, int i){
    // if(target==arr[i]) return true;
    if(i>=n || target<0) return false;
    if(target-arr[i]==0) return true;

    bool pick = f(n, target-arr[i], arr, i+1);
    if(pick) return true;

    bool notPick = f(n, target, arr, i+1);
    return notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n, k, arr, 0);
}