const int MOD = 1e9+7;

int findWays(vector<int>& arr, int k)
{
	int m= arr.size();
	vector<int>dp(k+1, 0);

	// for(int r=0; r<m; r++) {
	dp[0] += 1;
		// if(arr[r]==0) dp[r][0] += 1;
	// }
	if(arr[0]<=k)dp[arr[0]] += 1;
	

	for(int r=1; r<m; r++){
		for(int c=k; c>=0; c--){
			int take = 0;
			if(arr[r] <= c) take = dp[c-arr[r]];
			dp[c] = (dp[c] + take) % MOD;
		}
	}

	return dp[k]% MOD;

}
