#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result =0;
        int mn = prices[0], mx = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prices[i]<mx){
                result+=(mx-mn);
                mn = prices[i];
                mx = prices[i];
            }else{
                mx = prices[i];
            }
        }
        return result += (mx-mn);
    }
};

int main() {

    return 0;
}