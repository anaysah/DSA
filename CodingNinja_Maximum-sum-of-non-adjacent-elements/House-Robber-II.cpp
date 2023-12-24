#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/house-robber_839733

// this is continiuation of [Maximum sum of non-adjacent elements]https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
//dp 6 playlist striver 

long long int houseRobber(vector<int>& nums){
    long long p1 = 0; long long p2= nums[0];
    long long m1 = p2;
    int n = nums.size();

    for(int i=1; i<n-1; i++){
        p1 = nums[i] + ((i>1)?p2:0);
        p2 = m1;

        m1 = max(p1, p2);

    }

    p2 = nums[1]; long long m2=p2; p1=0;
    for(int i=2; i<n; i++){
        p1 = nums[i] + ((i>2)?p2:0);
        p2 = m2;

        m2 = max(p1, p2);
    }


    return max(m1, m2);
}