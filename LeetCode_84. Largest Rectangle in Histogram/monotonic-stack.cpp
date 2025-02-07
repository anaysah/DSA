#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


//LeetCode_84. Largest Rectangle in Histogram
//monotonic stack

//see the image for explanation

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st; 
        int n = heights.size();
        vector<int> ans(n);

        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.size()!=1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            ans[i] = (i - st.top() ) * heights[i];
            st.push(i);
        }


        st = stack<int>();
        st.push(n);
        int max_histogram_area=0;
        for(int i=n-1; i>=0; i--){
            while(st.size()!=1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            ans[i] += (st.top() - (i+1)) * heights[i];
            max_histogram_area = max(max_histogram_area, ans[i]);
            st.push(i);
        }

        return max_histogram_area;      
    }
};



void testLargestRectangleArea(vector<int> heights) {
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "The result is: " << result << endl;
}

int main(){
    vector<int> heights;

    // heights = {2,1,5,6,2,3};
    // testLargestRectangleArea(heights);

    heights = {2,4};
    testLargestRectangleArea(heights);

//     [2,1,5,6,2,3]
// [2,4]
// [1,2,1,2,1,1,2,1,2,2,0,2,1,3,1,2,1,0]
// [6,5,3,2,1,7,8,9]
// [4,3,2,1,2,3,4,6,7]
}