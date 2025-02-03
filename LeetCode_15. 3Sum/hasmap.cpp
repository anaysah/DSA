#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

//LeetCode 15. 3Sum

//things to remember
//1. this solution is using hashmap
//2. we are fixing the first element and the problem will become 2sum
//3. the idea is to reduce the 3sum problem into 2sum problem
//4. some basic maths is required to reduce the problem
//5. please remember that sum is 0 means this problem can be easily reduce to 2sum

// this solution will use O(n) space, but two pointer appraoch is better than this because that will not take space

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        for(int x=0; x<nums.size(); x++){
            unordered_map<int,int>mp;
            for(int z=x+1; z<nums.size(); z++){
                // int c = -nums[x]-nums[z];
                
                int c = -nums[x]-nums[z];
                if(mp.find(c)==mp.end()){
                    mp[nums[z]] = z;
                }else{
                    if(x!=z && z!=mp.find(c)->second && x!=mp.find(c)->second){
                        vector<int>temp = {nums[x],nums[z],nums[mp.find(c)->second]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        for(int i=0; i<ans.size(); i++){
            cout<<"["<<ans[i][0]<<", "<<ans[i][1]<<", "<<ans[i][2]<< "]";
        }
        return ans;
    }
};