#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//LeetCode 560. Subarray Sum Equals K


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_count;
        int count=0;
        prefix_sum_count[0] =1;
        int sum=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(prefix_sum_count.find(sum-k)!=prefix_sum_count.end()){
                count+=prefix_sum_count[sum-k];
            }
            prefix_sum_count[sum] +=1;
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