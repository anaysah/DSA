#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//LeetCode 496. Next Greater Element
// Monotonic Stack

//we just to maintain a stack with smaller to greatest value while traversing in back direction
// the elements which are smaller than the current element will be popped out from the stack
// because they will not help in finding the next greater element for the current element
// the top of the stack will be the next greater element for the current element
// if the stack is empty then there is no greater element for the current element
// we will store the next greater element for each element in a map

//see the diagram for more clearity


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int>mp; //[value, next_greater_value] this map will store the next greater element for each element
        //this unoredered_map is not usefull for solving the problem instead it is used because the elements in nums1 are unique and not in order as nums2
        mp[nums2[nums2.size()-1]] = -1;
        s.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2; i>=0; i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(!s.empty())mp[nums2[i]] = s.top();
            else mp[nums2[i]] = -1;
            s.push(nums2[i]);
        }

        vector<int>ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

void runAndPrint(vector<int>& nums1, vector<int>& nums2) {
    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    runAndPrint(nums1, nums2);

    nums1 = {2,4};
    nums2 = {1,2,3,4};
    runAndPrint(nums1, nums2);
    return 0;
}