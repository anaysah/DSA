#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVector2D(vector<vector<string>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    void subSequence(int n, vector<int>&col, vector<int>&row, int c,vector<string>&output,vector<vector<string>>&result){
        if(c>=n){
            result.push_back(output);
            return;
        }

        for(int r=0; r<n; r++){
            if(row[r]) continue;
            if(col[c]) continue;
            
            for(int t=1;t<n;t++){
                if(r-t>=0 && c-t>=0){
                    if (row[r-t] && col[c-t]) break;
                }
                if(r+1<n && c-t>=0){
                    if (row[r+t] && col[c-t]) break;
                }

                string s(n, '.');
                s[r] = 'Q';
                output.push_back(s);
                row[r] = 1;col[c] = 1;
                subSequence(n, row, col, c+1, output, result);
                output.pop_back();
                row[r] = 0;col[c] = 0;
                break;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>output;
        vector<vector<string>>result;
        vector<int>col(n, 0);vector<int>row(n, 0);
        subSequence(n, col, row, 0,output, result);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<string>>result = s.solveNQueens(4);
    // for(int i = 0; i < result.size(); i++){
    //     printVector2D(result[i]);
    // }
    printVector2D(result);
    return 0;
}