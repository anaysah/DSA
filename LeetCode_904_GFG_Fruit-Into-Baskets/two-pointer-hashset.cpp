#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
//Find length of the longest subarray containing atmost two distinct integers

// Given an array of integers, find the length of the longest subarray containing at most 2 distinct integers.

// hash_set which stores the last index of the element
// hash_set will only have atmost 2 elements

// when we get a element which is not in the hashset and also the size of hashset is 2
// means we have to form a new subarray
// so we will find the minimum index of the two elements in the hashset and update the left pointer to that index+1
// because we just need a subaaray without that element which is at minimum index means that element is prier
// so we will remove that element from the hashset
// also will calculate the length of the subarray and update the longest_subarray_length


class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int>hash_set; //[[value, last_index],...]
        int longest_subarray_length = 0;
        int left = 0, right=0;

        for(right=0; right<arr.size(); right++){
            if(hash_set.size()==2 && hash_set.find(arr[right])==hash_set.end()){
                longest_subarray_length = max(longest_subarray_length, (right)-left);
                auto it1 = hash_set.begin();
                auto it2 = std::next(it1);

                auto minPair = (it1->second < it2->second) ? it1 : it2;

                left = minPair->second +1;
                hash_set.erase(minPair);
            }

            hash_set[arr[right]] = right;
        }
        return max(longest_subarray_length, (right)-left);
    }
};

void runAndPrintResult(vector<int> &arr) {
    Solution solution;
    int result = solution.totalElements(arr);
    cout << result << endl;
}

int main(){
    vector<int> arr;
    arr = {1,2,1,2,3,3,4,4,4,4,1,2};
    runAndPrintResult(arr);

    cout<<endl;

    arr = {1,2,1,3,4,3,2,3,4};
    runAndPrintResult(arr);

    return 0;
}