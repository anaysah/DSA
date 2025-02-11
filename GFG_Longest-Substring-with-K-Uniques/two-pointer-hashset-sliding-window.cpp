#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// this is follow up question of GFG fruit-into-baskets
// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

// all the logic is same as fruit-into-baskets
// but we have to iterate hash_set to find the pair with minimum index
// because that element will be the oldest element and removing it we will have one more space and we can make a new substring
// so we will remove that element and update the left pointer to that index+1
// also we will calculate the length of the substring and update the longest_ss_length

// if we have reached the end of the string and still have k unique elements in the hash_set
// then we will calculate the length of the substring and update the longest_ss_length
// and return the longest_ss_length

// if we have not found the k unique elements in the string then we will return -1


class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int left=0, right=0;
        int longest_ss_length =0; //ss= substring
        unordered_map<char, int> hash_set; //[value, last_occurence_index]

        for(right; right<s.size(); right++){
            if(hash_set.size()==k && hash_set.find(s[right])==hash_set.end()){
                longest_ss_length = max(longest_ss_length, right-left);

                pair<char, int>min_index_pair={'\0', INT_MAX};
                for(auto &pair: hash_set){
                    if(pair.second<min_index_pair.second) min_index_pair = pair;
                }
                left = min_index_pair.second +1;
                hash_set.erase(min_index_pair.first);
            }
            hash_set[s[right]] = right;
        }
        if(hash_set.size()==k) {
            longest_ss_length = max(longest_ss_length, right-left);
            return longest_ss_length;
        }
        return -1;
    }
};

void runAndPrintResult(string &s, int k) {
    Solution solution;
    int result = solution.longestKSubstr(s, k);
    cout << result << endl;
}

int main(){
    string s;
    int k;
    s = "aabacbebebe";
    k = 3;
    runAndPrintResult(s, k);

    cout<<endl;

    s = "aabacbebebe";
    k = 2;
    runAndPrintResult(s, k);
    return 0;
}