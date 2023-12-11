#include <iostream>
#include <vector>

using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int recursion(int n, vector<int>&dp){
        
        int prev = 1;
        int prev2 = 1;
        // Running for loop to count all possible ways
        for (int i = 2; i <= n; i++) {
            int curr = (prev + prev2)% 1000000007;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int>dp(n+1, -1);
        return recursion(n, dp);
    }
};

int main(){
    Solution ob;
    cout<<ob.countWays(9)<<endl;
    return 0;
}