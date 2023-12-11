#include <iostream>
#include <vector>

using namespace std;

//testcases, first line n, second line k
/*
3
1
4
9
3
1
3
6
4
2
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;int fact=1;k=k-1;
        for(int i=1; i<n; i++){
            fact=fact*i;
            nums.push_back(i);
        }
        int ph = fact; //ph is per head
        nums.push_back(n);
        string s;
        while(true){
            int i = k/ph;
            s.push_back(char(48+nums[i]));
            nums.erase(nums.begin() + i);
            if(nums.size()==0) break;
            k=k%ph;
            ph = ph/nums.size();
        }
        return s;
    }
};