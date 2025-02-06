#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//Leetcode 907. Sum of Subarray Minimums
//so this my own solution which i came up with after knowing that this is a stack problem
// very hard to explain theirfore i will add explantion in future
// solution and approach my own but very hard to explain


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>> s; //[sum_upto_now, index_of_element]
        s.push(pair<int,int>{arr[0],0});
        const int MOD = 1e9 + 7;

        int current_sum = arr[0];

        for(int i=1; i<arr.size(); i++){
            while(!s.empty() && arr[i]<=arr[s.top().second]){
                s.pop();
            }

            pair<int,int>p;
            if(!s.empty()) {
                p.first = (s.top().first + ( (i - s.top().second) * arr[i])) % MOD;
            }
            else p.first = ( (i+1) * arr[i]) % MOD;
            p.second = i;
            s.push(p);
            // cout<<"pair"<<p.first<<" "<<p.second<<endl;

            current_sum = (p.first + current_sum) % MOD;

        }

        return current_sum;
    }
};

void testSumSubarrayMins(vector<int>& arr) {
    Solution sol;
    int result = sol.sumSubarrayMins(arr);
    cout << "The sum of all subarray minimums is: " << result << endl;
}

int main(){
    vector<int> arr = {3,1,2,4};
    testSumSubarrayMins(arr);

    // arr = {11,81,94,43,3};
    // testSumSubarrayMins(arr);

    // arr = {71,55,82,55,94,3,44,98,86,100};
    // testSumSubarrayMins(arr);
    // return 0;
}