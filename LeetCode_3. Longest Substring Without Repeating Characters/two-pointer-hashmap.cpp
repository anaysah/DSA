#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>character_set;
        int left=0; int right=0;
        int max_length = 0;
        while(right<s.size()){
            if(character_set.find(s[right])!=character_set.end()){
                max_length = max(max_length,right-left);
                int last_occurance_index = character_set[s[right]];
                for(int i=left; i<=character_set[s[right]]; i++) character_set.erase(s[i]);
                left = last_occurance_index + 1;
            }
            character_set[s[right]] = right;
            right++;
        }

        return max(max_length, right-left);
    }
};

void testLengthOfLongestSubstring(string s) {
    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
}

int main(){
    string s = "abba";
    testLengthOfLongestSubstring(s);
    return 0;
}