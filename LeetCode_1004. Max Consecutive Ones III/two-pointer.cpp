#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0;

        int max_consecutive_ones =0;

        while(right<nums.size()){
            if(nums[right]==0){
                k--;
                while(k<0){
                    if(nums[left]==0) {
                        k++;
                    };
                    left++;
                }
            }
            max_consecutive_ones = max(max_consecutive_ones, (right+1)-left);
            right++;
        }
        return max_consecutive_ones;
    }
};

void runAndPrintResult(vector<int>& nums, int k) {
    Solution solution;
    int result = solution.longestOnes(nums, k);
    cout << "The longest sequence of 1s with at most " << k << " zeros flipped is: " << result << endl;
}

int main(){
    vector<int> nums;
    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    runAndPrintResult(nums, k);

    cout<<endl;

    nums = {1,1,1,0,0,0,1,1,1,1,0};
    k = 2;
    runAndPrintResult(nums, k);


    return 0;
}