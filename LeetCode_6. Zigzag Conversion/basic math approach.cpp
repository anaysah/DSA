// 6. Zigzag Conversion 
// Basic Maths approach

// gap between all the elements in a row is 2*(numRows-1)
// to get the mid element is 2*(numRows-line-1)


// include everything
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        if(numRows==1) return s;
        int gap = 2 *(numRows-1);
        for(int line=0; line<numRows; line++){
            // cout <<"lineNO:"<< line << endl;
            int p=line;
            string ss="";
            while(p<s.size()){
                int mid = p + 2*(numRows-line-1);
                if(mid < s.size()) {   
                    ss += s[p];
                    if (mid!=p+gap) ss += s[mid];
                }
                else ss+=s[p];
                p=p+gap;
            }
            ans+=ss;
        }
        return ans;
    }
};

int main(){
    // write multiple test cases here
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("A", 1) << endl;
    cout << s.convert("AB", 1) << endl;
    cout << s.convert("AB", 2) << endl;
    cout << s.convert("AB", 3) << endl;
    
    return 0;
}