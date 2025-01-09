// Leetcode 121. Best Time to Buy and Sell Stock
// time complexity: O(n)
// space complexity: O(1)

// Approach: We will keep track of the minimum value and the maximum value of the subarray.
// we only have to focus on local minumum and maximum values
// if we get a new min value than we will find a new max value and update the result.

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size<=1) return 0;
        
        int min=prices[0],max=prices[0];
        int result=0;
        for (int i=1;i<size; i++){
            if(prices[i]<min){
                result= (result>(max-min)?result:(max-min));
                min=prices[i];
                max=prices[i];
            }
            if(prices[i]>max){
                max=prices[i];
            }
        }
        return result= (result>(max-min)?result:(max-min));;
    }
};