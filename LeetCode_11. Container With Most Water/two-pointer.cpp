#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//LeetCoce 11. Container With Most Water
// two pointer approach
// please no much thinking, their is no special cases to worry about

// just have a i and j pointer at start and end
// calculate the area and update the max_area
// move the pointer which has less height
// because the area is limited by the smaller height
// so if we move the pointer with larger height, the area will decrease
// so we move the pointer with smaller height
// this way we can find the maximum area

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int max_area = 0; 
        while(i<j){
            max_area = max(max_area, (j-i)*min(height[i],height[j]));
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return max_area;
    }
};

void testMaxArea(vector<int>& height) {
    Solution sol;
    int result = sol.maxArea(height);
    cout << "The maximum area is: " << result << endl;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    testMaxArea(height);

    height = {1,4,8,2,5,3,2,7,4,3};
    testMaxArea(height);

    height = {1,7,2,6,2,3,1};
    testMaxArea(height);

    height = {4,3,2,6,2,7,4};
    testMaxArea(height);
    return 0;
}