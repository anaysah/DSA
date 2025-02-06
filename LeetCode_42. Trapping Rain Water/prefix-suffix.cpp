#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Leetcode 42. Trapping Rain Water
//this is a other apporach with extra o(n) space
//we can use two arrays prefix and suffix which will store the maxium in froward direction and backward direction
//if at a current point we know that what is left maximum pole and right maximam pole than we can easilly find the water on top of current pole

//althouh i can use two arrays but i will use only one because that will also work
// will use a suffix array and a left_max_pole variable
//we just need to find left max pole and right max pole at a current pole
//then we can minus the current pole with min(left_max_pole, right_max_pole)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        int max_suffix[n];
        max_suffix[n-1] = height[n-1];
        int left_max_pole=height[0];

        int trapped_water =0;

        for(int i=n-2; i>=0; i--){
            if(max_suffix[i+1]<=height[i]) max_suffix[i] = height[i];
            else max_suffix[i] = max_suffix[i+1];
        }

        for(int i=1; i<n; i++){
            if(height[i]>=left_max_pole) left_max_pole = height[i];
            trapped_water+= min(max_suffix[i],left_max_pole) - height[i];
        }

        return trapped_water;
    }
};

void testTrap(vector<int>& height) {
    Solution sol;
    int result = sol.trap(height);
    cout << "The trapped water is: " << result << endl;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    testTrap(height);

    height = {4,2,0,3,2,5};
    testTrap(height);

    height = {0,1,0,3,1,4,2,0,2,4,3,2,1,0};
    testTrap(height);
    return 0;
}