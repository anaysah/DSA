#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//LeetCode 56. Merge Intervals
//"The version 2 is here because the previous code didn't work, and maybe I shouldn't push this to Git."

//Things to remember
//1. sorting is very imp.
//2. think of every possible testcases because their are no restricsion, you can see the code and images also for testcases
//3. try to draw the testcases on the number line
//4. overlapping is possible in any way. no restricsions on that
//5. if size of intervals is only one then no need to do any thing
//6. you have to return a new array without overlapping means all the intervals should be their even if it is not overlapping


// after sorting you just have to find min and max in local scope
// try to break the all sorted intervals in local scope
// 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(1>=intervals.size()) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> cur_interval = intervals[0]; // this will have a min and max
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=cur_interval[0] && intervals[i][0]<=cur_interval[1]){   // the nums[i][0] means starting dot should be in the min and max range
                if(intervals[i][1]>=cur_interval[1])
                    cur_interval[1] = intervals[i][1];
            }
            else {  // if the nums[i][0] starting dot is not in the min max means the 1 local scope is over and no overlapping will be find and we have to assign new min and max
                ans.push_back(cur_interval);
                cur_interval = intervals[i];
            }
        }
        ans.push_back(cur_interval); // this is important because we have to push the last local scope min max if it is still continuing after array finishes
        return ans;
    }
};

void runAndPrint(vector<vector<int>> intervals) {
    Solution sol;
    vector<vector<int>> result = sol.merge(intervals);
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    runAndPrint({{1,3},{2,6},{8,10},{15,18}});
    
    runAndPrint({{1,4},{4,5}});
    runAndPrint({{1,3},{2,6},{7,9},{8,11},{10,14}});
    runAndPrint({{1,3},{2,6},{7,9},{8,11},{7,12}});
    runAndPrint({{1,3},{2,6},{7,12},{8,11},{9,10}});
    runAndPrint({{1,3},{2,6},{7,12},{8,13},{9,10}});

    runAndPrint({{1,3},{2,6},{7,12},{8,13},{9,10},{14,19}});
    runAndPrint({{1,3},{2,6},{8,11},{9,13},{7,10},{14,19}});

    runAndPrint({{1,3},{2,6},{8,11},{9,13},{7,10},{7,10},{14,19}});

    runAndPrint({{2,10},{4,5},{6,9},{12,19},{1,20}});

}