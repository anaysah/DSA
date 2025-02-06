#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//LeetCode 402. Remove K Digits
//monotonic stack

// i am using string instead of stack
// the string is only having the elements which are in increasing order

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        ans.push_back(num[0]);
        for(int i=1; i<num.size(); i++){
            while(!ans.empty() && num[i]<ans[ans.size()-1]){
                if(k==0)break;
                ans.pop_back(); k--;
            }
            if(num[i]=='0' && ans.empty());
            else ans.push_back(num[i]);
        }
        if(ans.empty()) return "0";

        int j=ans.size();
        while(k>0){
            j--;
            k--;
        }
        if(j<=0) return "0";
        ans = ans.substr(0, j);
        return ans;
    }
};

void testRemoveKdigits(string num, int k) {
    Solution sol;
    string result = sol.removeKdigits(num, k);
    cout << "The result is: " << result << endl;
}

int main(){
    string num;

    num = "960000123845";
    int k = 8;
    testRemoveKdigits(num, k);

    // num = "1432219";
    // int k = 3;
    // testRemoveKdigits(num, k);

    // num = "10200";
    // k = 1;
    // testRemoveKdigits(num, k);
}