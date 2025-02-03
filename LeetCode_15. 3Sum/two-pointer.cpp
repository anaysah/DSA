#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 15. 3Sum

//to remember things
//1. ans should have unique triplets by numerber and not by index
//2. if nums[i] > 0 means we dont have to try futher because every numver after nums[i] will be bigger in sorted array
//3. also see if any pointer is not going out off bound
//4. this question still cant be reduce less than 0(n^2) but two pointer will not use o(n) space

// this solution is three pointer approach while the first pointer is used as traversing so this solution can be said as a two pointer approach
// sorting is also important in this because then only we can use the two pointer approach

// we will fix the i pointer and then we will use two pointer approach to find the sum of the other two elements
// if we fix the first pointer we need to find the other two elements

// we will take j=i+1 and k=last or nums.size()-1
// we will increase or decreaes j and k to find a perfect fit

// if we are getting cur_sum of all three equal to 0 then we can easily put it into ans vector
// if we getting less than 0 means we have increase the cur_sum to make it 0, we can do that by increase j so that we can have a big number add up in cur_sum
//while decrease j such that the new j doesn't have the same number because that will not help in increaseing the cur_sum
// if we getting more than 0 means we have decreases the cur_sum to make it 0, we can do that by decreasing k so that a smaller number can be added to cur_sum
//while decrease k such that the new k doesn't have the same number because that will not help in decreasing the cur_sum


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0,j,k,cur_sum;
        for(int i=0; i<nums.size(); i++){
            // while(i<nums.size() && nums[++i]==nums[i-1]){
            if (nums[i] > 0) break;
            j=i+1;k=nums.size()-1;
            while(j<k){
                cur_sum=nums[i]+nums[j]+nums[k];
                // cout<<cur_sum<<"="<<nums[i]<<", "<<nums[j]<<", "<<nums[k]<<endl;
                if(cur_sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    cout<<"["<<nums[i]<<", "<<nums[j]<<", "<<nums[k]<<"]"<<endl;
                    while(j+1<nums.size() && nums[++j]==nums[j-1]);
                    while(k-1>=0 && nums[--k]==nums[k+1]);
                }
                else if(cur_sum<0){
                    while(j+1<nums.size() && nums[++j]==nums[j-1]);
                }
                else if(cur_sum>0){
                    while(k-1>=0 && nums[--k]==nums[k+1]);
                }
                // cout<<cur_sum<<"  ";
                // cout<<i<<" "<<j<<" "<<k<<endl;
                // cout<<"["<<nums[i]<<", "<<nums[j]<<", "<<nums[k]<< "]";
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};

void printThreeSum(vector<int>& nums) {
    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout<<endl;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    printThreeSum(nums);

    // nums = {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2};
    // printThreeSum(nums);

    // nums={0,0,0};
    // printThreeSum(nums);
    return 0;
}