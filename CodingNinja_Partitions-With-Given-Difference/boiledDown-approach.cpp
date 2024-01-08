#include <bits/stdc++.h> 
int MOD = 1e9 + 7;
//https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628
//DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences

int countPartitions(int n, int d, vector<int> &arr) {
    int Sum = 0;
    for(int i=0;i<n; i++)Sum+=arr[i];
    if(Sum-d<0 || (Sum-d)%2!=0)return 0;
    int k = (Sum-d)/2;

    int m= n;
	vector<int>dp(k+1, 0);

	dp[0] += 1;
	if(arr[0]<=k)dp[arr[0]] += 1;
	

	for(int r=1; r<n; r++){
		for(int c=k; c>=0; c--){
			int take = 0;
			if(arr[r] <= c) take = dp[c-arr[r]];
			dp[c] = (dp[c] + take) % MOD;
		}
	}

	return dp[k]% MOD;
}


