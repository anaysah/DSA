// 1. Two Sum Easy/Optimal without Hash.cpp

// Optimized Approach(using two-pointer): 

// Intuition: In this approach, we will first sort the array and will try to choose the numbers in a greedy way.

// We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer. 

// If sum == target we will return either “YES” or the indices as per the question.
// But if the left crosses the right pointer, we will return “NO” or {-1, -1}.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left=0, right=nums.size()-1;

        while(left<right){
            int temp = nums[left] + nums[right];
            if (temp==target) return {nums[left], nums[right]};
            else if(temp>target) right--;
            else left++;
        }
        return {-1,-1};
    }
};