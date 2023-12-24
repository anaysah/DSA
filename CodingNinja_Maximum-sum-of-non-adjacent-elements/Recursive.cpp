#include <bits/stdc++.h>
using namespace std; 
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
//dp 5 playlist striver 

void f(vector<int> &nums, int i, int sum, int&result){
    if(i<0){
        result = max(result, sum);
        return;
    }

    sum+=nums[i];
    f(nums, i-2, sum, result);
    sum-=nums[i];
    f(nums, i-1, sum, result);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int result =0;
    f(nums, nums.size()-1, 0, result);
    return result;
}