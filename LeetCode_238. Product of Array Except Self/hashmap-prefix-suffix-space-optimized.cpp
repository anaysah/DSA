#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//LeetCode 238. Product of Array Except Self
//this is same approch but this time we have saved some space by using answer array itself for storing prefix

//the approach is simple, we can use the answer array itself to store the prefix in first traverse
// in second traverse we can find suffix and multiply with the prefix

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int prefix_product =1;

        for(int i=0; i<n; i++){
            ans[i] = prefix_product;
            prefix_product*=nums[i];
        }

        int suffix_product =1;

        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i] * suffix_product;
            suffix_product*=nums[i];
        }

        return ans;
    }
};

void runAndPrint(vector<int>& nums) {
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,2,3,4};
    runAndPrint(nums);
    return 0;
}