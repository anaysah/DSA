#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// LeetCode 239. Sliding Window Maximum
// monotonic queue
// deque will have from greatest to smallest
// because we need just first greater element from the start on the left side
// so we can pop all the elements which are smaller than current element


// deque is used because we need the greatest value which will be stored in the first position of the max stack
// and also we need to remove the element from the start if it is not in current range
// we used deque becuase it gives pop_front and front value


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans; //[value, value,...]
        deque<int> doubeque; //[index, index, ...]
        

        for(int i=0; i<k; i++){
            while(!doubeque.empty() && nums[doubeque.back()]<=nums[i]){
                doubeque.pop_back();
            }
            doubeque.push_back(i);
        }
        ans.push_back(nums[doubeque.front()]);

        for(int i=k; i<nums.size(); i++){
            while(!doubeque.empty() && nums[doubeque.back()]<=nums[i]){
                doubeque.pop_back();
            }
            doubeque.push_back(i);
            if(doubeque.front()<=i-k) doubeque.pop_front();
            ans.push_back(nums[doubeque.front()]);
        }

        return ans;
    }
};

void runAndPrintResult(vector<int>& nums, int k) {
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums;
    
    nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    runAndPrintResult(nums, k);

    // nums = {1};
    // k = 1;
    // runAndPrintResult(nums, k);

    // nums = {1,-1};
    // k = 1;
    // runAndPrintResult(nums, k);

    // nums = {9,11};
    // k = 2;
    // runAndPrintResult(nums, k);

    // nums = {4,-2};
    // k = 2;
    // runAndPrintResult(nums, k);

    // nums = {1,3,1,2,0,5};
    // k = 3;
    // runAndPrintResult(nums, k);

    // return 0;
}