#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

//LeetCode49. Group Anagrams
// Time complexity: O(m * n log n)  nlogn for sorting and m is size of vector
// Space complexity: O(m * n) but if sorting takes o(1) than i think o(m) will be the complexity

//use sorting to sort the string and save in a hashmap all the string with same sorted string
//se the image sorting-n-hashmap.jpg for more info and diagram

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string s: strs){
            string temp_s = s;
            sort(temp_s.begin(), temp_s.end());

            mp[temp_s].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &pair: mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};

void runAndPrintAnagrams(vector<string>& strs) {
    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    runAndPrintAnagrams(strs);
    return 0;   
}