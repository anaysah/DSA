#include <iostream>
#include <vector>
using namespace std;

//LeetCode_169_229. Majority Element
//Boyer-Moore Majority Vote Algorithm

// in majority 1
// one candidate cancel others vote
// in majority 2
// one candedate cancel 2 different vote

// neutralization is important in both cases

// try to tkink of a logic in which we can cancel out the votes of the other candidates

// in majority 1
// if we have 1 vote for candidate 1 then candidate 1 is the majority
// but next moment if we have 1 vote for candidate 2 then we dont have majority now

// same logic goes in majority 2
// if we have 1 vote for candidate 1 and 1 vote for candidate 2 then we dont have majority now
// just one extra vote for candidate 3 will cancel both the votes of candidate 1 and candidate 2
// means these 3 votes are now neutralized and the array can be seen as if these 3 votes are not present in the array

class Solution {
    public:

    vector<int> majorityElement(vector<int>& nums) {
        // Step 1: First pass to find potential candidates
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Second pass to validate candidates
        vector<int> res;
        count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) count1++;
            if (num == candidate2) count2++;
        }

        if (count1 > nums.size() / 3) res.push_back(candidate1);
        if (count2 > nums.size() / 3 && candidate1 != candidate2) res.push_back(candidate2);

        return res;
    }
};

void testResult(vector<int>& nums, vector<int>& expected) {
    Solution s;
    vector<int> result = s.majorityElement(nums);
    cout << "Result: ";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    cout << "Expected: ";
    for(int i=0; i<expected.size(); i++){
        cout<<expected[i]<<" ";
    }
    cout<<endl;
    // if (result == expected) {
    //     cout << "Test passed!" << endl;
    // } else {
    //     cout << "Test failed!" << endl;
    // }
}

int main(){
    vector<int> nums = {7,7,1,3,2,3,3,2,2,3};
    vector<int> expected = {3};
    testResult(nums, expected);

    return 0;
}