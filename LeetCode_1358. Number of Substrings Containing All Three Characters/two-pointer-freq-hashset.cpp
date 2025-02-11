#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Leetcode 1358. Number of Substrings Containing All Three Characters

//remember that we have return the number of substrings containing all three characters not all the substrings

//when ever we have all the three character in the freq_hashset
// we can add 1 and the number of substrings from right to end of the string
// then we can move the left pointer to right until we have all the three characters
// while moving left pointer we can add 1 and the number of substrings from right to end of the string

//the main approach is to always keep the window with alteast one all the three characters

//if we get remainging character at the last position then we have to do the same process again but the first for loop will not run
// thatwhy i have added the if condition after the for loop again. this is done due to the edge case when we find the last remaining character at the last position

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, right=0;
        int subarray_count=0;
        unordered_map<char, int>freq_hashset;

        for(right;right<s.size();right++){
            if((freq_hashset['a'] && freq_hashset['b'] && freq_hashset['c'])){
                subarray_count+= 1 + (s.size()-right);
                while(--freq_hashset[s[left]]!=0){
                    left++;
                    subarray_count+= 1 + (s.size()-right);
                }
                left++;
            }
            // if(right==s.size()) break;
            freq_hashset[s[right]]++;
        }
        if(freq_hashset['a'] && freq_hashset['b'] && freq_hashset['c']){
            subarray_count+= 1 + (s.size()-right);
            while(--freq_hashset[s[left]]!=0){
                left++;
                subarray_count+= 1 + (s.size()-right);
            }
            left++;
        }
        return subarray_count;
    }
};

int main(){
    Solution solution;
    string s = "abcabc";
    int result = solution.numberOfSubstrings(s);
    cout << result << endl;
}