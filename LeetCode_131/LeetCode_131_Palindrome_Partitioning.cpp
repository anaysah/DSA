#include <iostream>
#include <vector>
using namespace std;

//testcases
/*
"aab"
"kabal"
"aazkbb"
"aba"
"aka"
"klaba"
"naman"
"abakj"
*/

//create a function named printVector to print the vector of vector of string

void printVector(vector<vector<string>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    bool palindrome(string s, int x, int y){
        y--;
        while(x < y){
            if(s[x]!= s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void subSequence(string s, int a, vector<string>&output, vector<vector<string>>&result){
        if(a>=s.length()){
            result.push_back(output);
            return;
        }

        for(int i=a+1;i<=s.length();i++){
            if(!palindrome(s, a, i)) continue;
            output.push_back(s.substr(a, i-a));
            subSequence(s, i, output, result);
            output.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> result;
        subSequence(s, 0, output, result);
        return result;
    }
};

int main(){
    cout<<"breakpoint 1"<<endl;
    Solution s;
    vector<vector<string>> result;
    result = s.partition("naman");
    printVector(result);
    cout<<"breakpoint 2"<<endl;
    return 0;
}