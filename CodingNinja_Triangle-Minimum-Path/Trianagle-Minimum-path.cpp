#include <bits/stdc++.h> 
using namespace std;
//Minimum Path Sum
//https://www.codingninjas.com/studio/problems/triangle_1229398
//Striver DP 11. Triangle | Fixed Starting Point and Variable Ending Point | DP on GRIDS

int minimumPathSum(vector<vector<int>>& triangle, int n){
	int m = triangle.size();
	for(int r=m-2; r>=0; r--){
		int n = triangle[r].size();
		for(int c=n-1; c>=0; c--){
			// int down=INT_MAX, downPlus = INT_MAX;

			int down = triangle[r+1][c];
			int downPlus = triangle[r+1][c+1];

			triangle[r][c] = triangle[r][c] + min(down, downPlus);
		}
	}
	return triangle[0][0];
}