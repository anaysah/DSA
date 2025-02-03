#include <iostream>
#include <vector>
using namespace std;

//very easy two pointer problem
//time complexity: O(n)

//if cur_sum is greater than target, then we need to decrease the sum, so we decrease j
//if cur_sum is less than target, then we need to increase the sum, so we increase i
//if cur_sum is equal to target, then we found the solution, so we return the indices

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        int cur_sum;
        while(i<j){
            cur_sum = numbers[i] + numbers[j];
            if(cur_sum==target) return {i,j};
            else if(cur_sum>target) j--;
            else if(cur_sum<target) i++;
        }
        return {};
    }
};

void runAndPrintTwoSum(vector<int>& numbers, int target) {
    Solution sol;
    vector<int> res = sol.twoSum(numbers, target);
    if (!res.empty()) {
        cout << res[0] << " " << res[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
}

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    runAndPrintTwoSum(numbers, target);

    numbers = {-6,-5,-4,-3,-2,-1};
    runAndPrintTwoSum(numbers, -6);

    numbers = {-6,-5,-2,-1,6};
    runAndPrintTwoSum(numbers, -6);

    numbers = {2,3,4};
    runAndPrintTwoSum(numbers, 6);

    numbers = {-1,0};
    runAndPrintTwoSum(numbers, -1);
    return 0;
}