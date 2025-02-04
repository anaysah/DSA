#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//LeetCode 242. Valid Anagram
// anagram means both array or sting should look the same after sorting
// the size of both should be same
// every character should occur in same number in both stings
// the both string can be ramdom but after sorting should be same


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};