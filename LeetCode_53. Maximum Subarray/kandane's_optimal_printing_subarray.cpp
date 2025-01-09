//Leetcode 53. Maximum Subarray

//optimal solution with kanade's algorithm
//Time complexity: O(n)
//Space complexity: O(1)
//Approach: We will keep track of the sum of the subarray and if the sum is greater than the max value then we will update the max value.
//If the sum is less than or equal to 0 then we will reset the sum to 0.
//if a subarray is having negative sum then it is better to start from the next element.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], sum =0;
        int start=0,end=0;
        for(int i=0; i<nums.size(); i++){
            sum +=nums[i];
            if(sum>max) {
                end = i;
                max = sum;
            }
            if(sum<=0){
                start = i+1;
                sum=0;
            }
        }
        for(int i=start; i<=end; i++){
            cout<<nums[i]<<" ";
        }
        return max;
    }
};

int main(){
    // make many VECTORs and call the function to test the code
    Solution sol;
    vector<int> vec1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> vec2 = {1};
    vector<int> vec3 = {5, 4, -1, 7, 8};
    vector<int> vec4 = {-1, -2, -3, -4};
    vector<int> vec5 = {8, -19, 5, -4, 20};

    cout << "Max Subarray Sum for vec1: " << sol.maxSubArray(vec1) << endl;
    cout << "Max Subarray Sum for vec2: " << sol.maxSubArray(vec2) << endl;
    cout << "Max Subarray Sum for vec3: " << sol.maxSubArray(vec3) << endl;
    cout << "Max Subarray Sum for vec4: " << sol.maxSubArray(vec4) << endl;
    cout << "Max Subarray Sum for vec5: " << sol.maxSubArray(vec5) << endl;

    return 0;
}