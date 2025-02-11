#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//LeetCode 904. Fruit Into Baskets
// this question is same as on GFG but in the soltion is different

// in this approach we are using freq_hashset to store the frequency of the fruits
// when ever we get a new fruit which is same as two fruits in the basket
// we will start removing fruits from the left side of the window by decreasing the frequency of the fruit
// at a point when frequency of the fruit means we have fully removed that furit from the basket and one more fruit can be added
// we will remove that fruit from the freq_hashset
// and increase the left pointer by 1
// and then add the new fruit to the freq_hashset
// and continue the process

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, right=0;
        // int max_fruits=0;
        // int cur_fruits=0;
        int max_trees=0;

        unordered_map<int, int>freq_hashset;
        
        for(right; right<fruits.size(); right++){
            if(freq_hashset.size()==2 && freq_hashset.find(fruits[right])==freq_hashset.end() ){
                max_trees = max(max_trees, right-left);
                while(--freq_hashset[fruits[left]]!=0){
                    left++;
                }
                freq_hashset.erase(fruits[left]);
                left++;
            }
            freq_hashset[fruits[right]]++;
            // cout<<"left: "<<left<<" right: "<<right<<" cur_fruits: "<<cur_fruits<<endl;
        }
        return max(max_trees, right-left);
    }
};

void runAndPrintResult(vector<int> &fruits) {
    Solution solution;
    int result = solution.totalFruit(fruits);
    cout << result << endl;
}

int main(){
    vector<int> fruits;
    fruits = {0,1,2,2};
    runAndPrintResult(fruits);

    cout<<endl;

    // fruits = {1,2,1,3,4,3,2,3,4};
    // runAndPrintResult(fruits);
}