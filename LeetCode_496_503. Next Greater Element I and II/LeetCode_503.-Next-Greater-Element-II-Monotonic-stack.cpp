#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// 503. Next Greater Element II
// this is the same as the previous problem but the array is circular
// it did this approch myself with the help of previous problem

// we can do the same as the previous problem but this time we will have a not_found vector
//if array of size 10 then maybe not_found vector will look like [9, 7,4]
// which will store the indexes of the elements which are not found in the first iteration
// then we will iterate over the not_found vector and find the next greater element for the elements which are not found in the first iteration
// we will use the same stack 

//we have a different approach also
// we can make the vector twice size and store the array again
// new array will be of size n*2


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int>ans(nums.size());
        int n=nums.size();
        vector<int>not_found={n-1}; //[index_of_element_not_found] //this will store the elements whose greatest element not found in first time

        ans[ans.size()-1] = -1;
        s.push(nums[n-1]);

        for(int i=n-2; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(!s.empty())ans[i] = s.top();
            else {
                ans[i] = -1;
                not_found.push_back(i);
            }
            s.push(nums[i]);
        }

        for(int i: not_found){
            if(ans[i]==-1){
                while(!s.empty() && s.top()<=nums[i]) s.pop();

                if(!s.empty())ans[i] = s.top();
                else ans[i] = -1;
                s.push(nums[i]);
            }
        }

        return ans;
    }
};

void printNextGreaterElements(vector<int>& nums) {
    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    // vector<int> nums = {1,2,1};
    // printNextGreaterElements(nums);

    // nums = {1,2,3,4,3};
    // printNextGreaterElements(nums);

    // nums = {4,2,3,6,1,2,8,7,6,2,3,1,2,1,5,4,2};
    vector<int> nums = {1, 8, -1, -100, -1, 222, 1111111, -111111};
    printNextGreaterElements(nums);

    return 0;
//     [1,2,1]
// [1,2,3,4,3]
// [4,2,3,6,1,2,8,7,6,2,3,1,2,1,5,4,2]
// [1,8,-1,-100,-1,222,1111111,-111111]
// [9,8,6,5,3,1,0]
// [0,3,4,6,8,9,10]
// [11,3,4,6,8,9,10]
// [2,5,7,9,8,6,5,3,1,0]
// [-1,-1,-2,-100,100,-110,-20202,39303,-9,9]
// [-101,737383,29283,920,393883,-9383,-903,-38]
}