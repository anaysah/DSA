#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//LeetCode 238. Product of Array Except Self

//we just need two array which can works as hashmap
//we can traverse one time and store the prefix product and suffix product in those array
//then we can traverse one more time and calculate product with prefix and suffix array
//this appraoch is very easy and can be implemented easilly
// did on myslef, just written if i read in future so i will be happy


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prefix_product=1;
        int suffix_product=1;

        int prefix[n];
        int suffix[n];

        for(int i=0; i<n; i++){
            prefix_product*= nums[i];
            prefix[i] = prefix_product;

            suffix_product*=nums[n-i-1];
            suffix[n-i-1] = suffix_product;
        }

        vector<int>ans(n);
        prefix_product = 1; suffix_product =1;
        for(int i=0; i<n; i++){
            if(i-1>=0) prefix_product = prefix[i-1];
            else prefix_product = 1;
            if(i+1<n) suffix_product = suffix[i+1];
            else suffix_product = 1;
            
            ans[i] = prefix_product*suffix_product;
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