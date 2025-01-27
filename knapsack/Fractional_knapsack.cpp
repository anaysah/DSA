#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Fractional knapsack problem

// explanation
// by using pair, we can store the ratio of profit/weight and the index of the item
// then we sort the pair in descending order
// then we iterate through the sorted pair and check if the weight of the item is less than the remaining weight
// if it is, we add the profit of the item to the max_profit and subtract the weight of the item from the remaining weight
// if it is not, we add the profit of the item to the max_profit and multiply the remaining weight with the ratio of profit/weight
// then we return the max_profit

// time complexity: O(nlogn)
// space complexity: O(n)

double Fractional_knapsack(int n, int W, int w[], int v[]){
    vector<pair<double,int>> pw_ratio(n);
    for(int i=0; i<n; i++){
        pw_ratio[i] = make_pair((double)v[i]/w[i], i);
        cout << pw_ratio[i].first <<" ";
    }
    cout << endl;
    sort(pw_ratio.begin(), pw_ratio.end()); // sort in descending order

    int left_weight = W;
    double max_profit = 0;
    for(int i=n-1; i>=0; i--){
        int index = pw_ratio[i].second;
        if(w[index] <= left_weight){
            max_profit += v[index];
            left_weight -= w[index];
            cout << v[index]<<" + ";
        }else{
            max_profit += (double)(left_weight*pw_ratio[i].first);
            cout << left_weight*pw_ratio[i].first<<" = ";
            break;
        }
    }
    return max_profit;
}

int main(){
    int n = 7;
    int W = 18;
    int w[] = {3,4,6,8,2,2,3};
    int v[] = {15,5,20,8,7,20,6};
    cout << Fractional_knapsack(n, W, w, v) << endl;
    return 0;
}