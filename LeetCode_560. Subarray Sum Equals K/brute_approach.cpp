#include <iostream>
#include <vector>
using namespace std;

//LeetCode 560. Subarray Sum Equals K
//brute force approach O(n^2)


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;

        for(int traversing_index=0; traversing_index<nums.size(); traversing_index++){
            //i(trversing_index) is not being used for pointer or something
            // it is just their for starting of new subarray
            //we have choose a new starting point of a subarray to make new subarrays
            //dont confuse the traversing_i with i, it is just for starting point of subarray
            int sum=0;
            for(int j=traversing_index; j<nums.size(); j++){
                sum+=nums[j];
                if(sum==k) count++;
            }
        }

        return count;
    }
};

void testSubarraySum(vector<int>& nums, int k, int expected) {
    Solution s;
    int result = s.subarraySum(nums, k);
    cout << "Result: " << result << ", Expected: " << expected << endl;
    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

int main(){
    vector<int> nums = {1, 1, 1};
    testSubarraySum(nums, 2, 2);

    nums = {1, 2, 3};
    testSubarraySum(nums, 3, 2);

    nums = {1, 2, 3, 4};
    testSubarraySum(nums, 3, 2);

    nums = {1,2,3,-3,1,1,1,4,2,-3};
    testSubarraySum(nums, 3, 8);

}