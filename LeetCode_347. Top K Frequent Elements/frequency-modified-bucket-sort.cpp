#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//LeetCode 347. Top K Frequent Elements
//hashmap and modifed bucket sort is used

// use hashmap for saving counts
// make a frequency bucket with size of nums.size()+1
// push the values in the bucket based on their frequency

// push the values from the back of the bucket into ans vector upto kth element
//see the diagram for better understanding

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp; //[value, count]
        for(int value: nums){
            mp[value]++;
        }
        vector<vector<int>> freq_bucket(nums.size()+1,vector<int>{});
        for(auto& pair: mp){
            freq_bucket[pair.second].push_back(pair.first);
        }
        vector<int>ans;
        for(int i=freq_bucket.size()-1; i>=0 && k!=0; i--){
            for(int j=0; j<freq_bucket[i].size(); j++){
                ans.push_back(freq_bucket[i][j]); k--;
            }
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