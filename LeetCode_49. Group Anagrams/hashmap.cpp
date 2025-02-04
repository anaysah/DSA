#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


//LeetCode49. Group Anagrams
// Time & Space Complexity
// Time complexity: O(m * (n+26))
// Space complexity: O(m)

// make unique key for all stings with the help of count
//like eat = "a1e1t1"
// string which has the same key will be stored together
//see the image hashing-n-unique-key.jpg for more info and diagram


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            int count[26] = {0};
            for(char c: s){
                count[c-'a']++;
            }

            string key = to_string(count[0]);
            for(int value: count){
                key+="," + to_string(value);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& pair: mp){
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