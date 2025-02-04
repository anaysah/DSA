#include <iostream>
#include <vector>
using namespace std;

//LeetCode 152. Maximum Product Subarray
//code written by myself by hint taken from youtube

//To remember
//1. input has zero also
//2. every possible testcases can be given with negative, positive, zero values

//observation
//1. 0 will break the array into multiple array which can be done individually
//2. in a smaller array(breaked due to zeros) if we have even negative than no problem because minus will cut minus
//3. if negative is odd then their is problem because we have exclude one negative value either from the start or from the end

// we are finding prefix and suffix for all local arrays
// but we are not finding the prefix and suffix of same local array at the same time

// the main logic is go in forward and backward direction at same sime of the main array
// this will find all the prefix_product and suffix_product of a local array but at a different
// when ever we get a 0 we can set a new value for suffix and prefix

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_product=INT_MIN;
        int prefix_product = 1;
        int suffix_prodcut = 1;

        for(int i=0; i<nums.size(); i++){
            prefix_product*=nums[i];
            suffix_prodcut*=nums[n-i-1];
            max_product = max(max_product, prefix_product);
            max_product = max(max_product, suffix_prodcut);
            if(nums[i]==0) prefix_product =1;
            if(nums[n-i-1]==0) suffix_prodcut =1;
        }
        return max_product;
    }
};

void testMaxProduct(vector<int>& nums) {
    Solution sol;
    int result = sol.maxProduct(nums);
    cout << "The maximum product is: " << result << endl;
}

int main(){
    vector<int> nums1 = {2,3,-2,0,4};
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl<<endl;
    testMaxProduct(nums1);

// [2,3,-2,0,4]
// [-2,0,-1,0,6,0,-6,0]
// [-2,3,0,-1]
// [-2,3,0,4,-1]
// [0,3,5,-5,3,0]
// [0,3,5,-1]
// [0,3,5,-1,4,-6]
// [0,3,5,-1,4,-6,5]
// [0,0,0,0]
// [0]
// [0,-2,0]
// [-2,0,-4]
// [2,-2,0,-5]
}