#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//LeetCode 347. Top K Frequent Elements
//this is a naive solution using hashmap and sorting
//sorting is more important for this approach

//save the count of every element in hashmap
//sort with the help of vector based on count

//push from back of the sorted vector into ans vector upto kth element

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp; //[value, count]
        for(int value: nums){
            mp[value]++;
        }
        vector<vector<int>> data; //[[count, value],[count, value],...]
        for(auto& pair: mp){
            data.push_back({pair.second, pair.first});
        }
        sort(data.begin(), data.end());

        vector<int> ans(k);
        for(int i =0; i<k; i++){
            ans[i]=data[data.size()-i-1][1];
        }
        return ans;
    }
};

void printTopKFrequent(vector<int>& nums, int k) {
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    printTopKFrequent(nums, k);
    return 0;
}