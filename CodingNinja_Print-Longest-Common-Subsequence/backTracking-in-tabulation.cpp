#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383
//DP 27. Longest Common Substring | DP on Strings

string findLCS(int n, int m,string &text1, string &text2){
	int i=text1.size();
	int j=text2.size();
	vector<vector<int>> dp(i+1, vector<int>(j+1,0));

	for(int r=1; r<=i; r++){
		for(int c=1; c<=j; c++){
			if(text1[r-1]==text2[c-1]){
				dp[r][c] = 1 + dp[r-1][c-1];
			}
			else{
				dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
			}
		}
	}
	int c=dp[i][j];
	string s(c,' ');

	int x=i, y=j;
	while(x>0 && y>0){
		if(text1[x-1]==text2[y-1]){
			s[--c] = text1[x-1];
			x--;y--;
		}else{
			if(dp[x-1][y]>dp[x][y-1]){
				x--;
			}else{
				y--;
			}
		}
	}
	// cout<<s;

	return s;
}