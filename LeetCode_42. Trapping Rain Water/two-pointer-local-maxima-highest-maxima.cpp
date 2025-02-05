#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//LeetCoce 42. Trapping Rain Water
// hard problem but i did it on my own but knew the two pointer can help because i took this question from the neetcode roadmap
// the solution which i have did isnot matching with the solution of needcode
// still my solution is correct and i am happy with it

//things to remember
//1. local maxima
//2. highest pole divides the array into two subarrays

// what the hell, i dont think this is an hard problem. i did the solution very easilly and i have never done it in the past. 
// try "11. Container With Most Water "medium problem first because i did and when i tried this it looked simple

// we are kind  of use two pointer approach here because
// but j pointer is only traversing normally
// i is chainging postion according to j

// the approach is very simple
// the pole which has the max height rules the game
// on the left side of the pole, the water is limited by the pole
// on the right side also the water is limited by the pole
// the max pole divides the array into two subarrays or subproblems

// we can have local maxima
// if we got a pole which is greater than the maxima pole, then we have to update the maxima pole
// until then we can keep adding the water trapped by the poles

// in above process when j get to the most heightest pole the trapped water is calculated cant be calculated futher
// but we will get the maximum heigh pole

// we can traverse one more time but this time from the last
// because the highest pole divied the array into two subarrays
// no do the same but in reverse order upto the maximum pole


class Solution {
public:
    int trap(vector<int>& height) {
        int cur_max_i =0; //this i pointer
        int trapped_water = 0; int cur_trapped_water =0;
        for(int j=0; j<height.size(); j++){
            if(height[cur_max_i]>=height[j]){
                cur_trapped_water+=height[cur_max_i]-height[j];
            }else{
                trapped_water+=cur_trapped_water;
                cout<<cur_trapped_water<<" ";
                cur_trapped_water =0;
                cur_max_i =j;
            }
        }
        // cout<<"curmaxi"<<cur_max_i<<" ";

        cur_trapped_water =0;
        int back_cur_max_i = height.size()-1;
        for(int j=height.size()-1; j>=cur_max_i; j--){
            if(height[back_cur_max_i]>height[j]){
                cur_trapped_water+=height[back_cur_max_i]-height[j];
            }else{
                trapped_water+=cur_trapped_water;
                cout<<cur_trapped_water<<" ";
                cur_trapped_water =0;
                back_cur_max_i =j;
            }
        }
        // trapped_water+=cur_trapped_water;
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