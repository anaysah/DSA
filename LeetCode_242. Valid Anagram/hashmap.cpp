#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
using namespace std;

//LeetCode 242. Valid Anagram
// anagram means both array or sting should look the same after sorting
// the size of both should be same
// every character should occur in same number in both stings
// the both string can be ramdom but after sorting should be same


// this is hashmap solution
// we dont actually need hashmap because their are only 26 character in alphabet so we can use array instead


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return false;
        int hm[26] = {0};
        for(char c: s){
            hm[c-'a']++;
        }
        for(char c: t){
            hm[c-'a']--;
        }
        for(int value: hm){
            if(value!=0) return false;
        }
        return true;
    }
};