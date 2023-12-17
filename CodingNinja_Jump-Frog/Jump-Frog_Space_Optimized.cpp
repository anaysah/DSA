#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    if(n==1) return 0;

    int left=0;int right=0;

    for(int i=1;i<n;i++){
        int temp = left;
        left = left + abs(heights[i]-heights[i-1]);

        if (i>1)
        right = right + abs(heights[i]-heights[i-2]);
        else right = INT_MAX;

        left = min(left, right);
        right = temp;
    }

    return left;
}