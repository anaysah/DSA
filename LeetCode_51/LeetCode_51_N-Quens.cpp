#include <iostream>
#include <vector>

using namespace std;

//write a function to print a vector
void printVector(vector<int> v)
{
    cout<<"[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<"] ";
    // cout << endl;
}

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
    void subSequence(int n, vector<int>&col, int r,vector<string>&output,vector<vector<string>>&result){
        if(r>=n){
            result.push_back(output);
            return;
        }

        for(int c=0; c<n; c++){
            if(col[c]!=-1) continue; // if that column is already occupied dont run

            //this forloop check if the diagonal have any queens
            bool flag = false;
            for(int t=1;(r-t>=0 && c-t>=0) || (r-t<n && r-t>=0 && c+t<n);t++){
                if(r-t>=0 && c-t>=0){
                    if(col[c-t]==r-t) {flag = true;break;}
                }

                if(r-t<n && r-t>=0 && c+t<n){
                    if(col[c+t]==r-t) {flag = true;break;}
                }
                
            }
            if(flag==false){  //if column is not occupied and diagonals are also freee
                string s(n, '.');
                s[c] = 'Q';
                output.push_back(s);
                col[c] = r;
                subSequence(n, col, r+1, output, result);
                output.pop_back();
                col[c] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>output;
        vector<vector<string>>result;
        vector<int>col(n, -1);
        subSequence(n, col, 0,output, result);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<string>>result = s.solveNQueens(4);
    printVector2D(result);
    return 0;
}