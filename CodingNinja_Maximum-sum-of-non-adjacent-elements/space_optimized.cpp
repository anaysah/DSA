#include <bits/stdc++.h>
using namespace std; 
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
//dp 5 playlist striver 

int maximumNonAdjacentSum(vector<int> &nums){
    int p1 = 0; int p2= nums[0];
    int m = p2;


    for(int i=1; i<nums.size(); i++){
        p1 = nums[i] + ((i>1)?p2:0);
        p2 = m;

        m = max(p1, p2);
    }

    return m;
}