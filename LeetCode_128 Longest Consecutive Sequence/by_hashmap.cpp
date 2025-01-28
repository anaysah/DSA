#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//Leetcode 128. Longest Consecutive Sequence

//use haspmap to store the elements
//for each element, check if the previous element is present in the set
//if not, then it is the start of a new sequence
//find the length of the sequence and update the longestConsecutive
//O(n) solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestConsecutive = 0;
        for(int num: numSet){
            if(numSet.find(num-1)==numSet.end()){
                int currentLongestConsecutive = 1; 
                for(int i=1; i<nums.size() && numSet.find(num+i)!=numSet.end(); i++) currentLongestConsecutive++;
                longestConsecutive = max(longestConsecutive, currentLongestConsecutive);
            }
        }

        return longestConsecutive;
    }
};

void runTest(vector<int> nums, int expected) {
    Solution sol;
    int result = sol.longestConsecutive(nums);
    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed! Expected " << expected << " but got " << result << endl;
    }
}

int main() {
    runTest({100, 4, 200, 1, 3, 2}, 4); // 1, 2, 3, 4
    runTest({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9); // 0, 1, 2, 3, 4, 5, 6, 7, 8
    runTest({1, 2, 0, 1}, 3); // 0, 1, 2
    runTest({}, 0); // Empty array
    runTest({1}, 1); // Single element
    runTest({1, 2, 2, 3}, 3); // 1, 2, 3
    runTest({1, 2, 2, 3, 3, 3}, 3); // 1, 2, 3
    runTest({1, 2, 2, 3, 3, 3, 4, 4, 4, 4}, 4); // 1, 2, 3, 4
    runTest({1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}, 5); // 1, 2, 3, 4, 5

    runTest({10, 5, 12, 3, 55, 30, 31, 32, 33, 34}, 5); // 30, 31, 32, 33, 34
    runTest({1, 9, 3, 10, 4, 20, 2}, 4); // 1, 2, 3, 4
    runTest({5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 11); // 5 to 15
    runTest({-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, 10); // -10 to -1
    runTest({1, 3, 5, 7, 9, 11, 13, 15}, 1); // No consecutive sequence
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, 20); // 1 to 20
    runTest({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110}, 11); // 100 to 110
    runTest({-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}, 11); // -5 to 5
    runTest({1, 2, 3, 10, 11, 12, 20, 21, 22}, 3); // Multiple sequences of length 3
    return 0;
}