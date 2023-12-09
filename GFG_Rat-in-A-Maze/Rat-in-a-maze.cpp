#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void subSequence(vector<vector<int>> &m, int n, int r, int c, vector<string>&result, string&output){
        if(r==n-1 && c==n-1){
            result.push_back(output);
            return;
        }
        
        if(c+1<n && m[r][c+1]){
            output.push_back('R');
            m[r][c] = 0;
            subSequence(m, n, r, c+1, result, output);
            m[r][c] = 1;
            output.pop_back();
        }
        if(r+1<n && m[r+1][c]){
            output.push_back('D');
            m[r][c] = 0;
            subSequence(m, n, r+1, c, result, output);
            m[r][c] = 1;
            output.pop_back();
        }
        if(c-1>=0 && m[r][c-1]){
            output.push_back('L');
            m[r][c] = 0;
            subSequence(m, n, r, c-1, result, output);
            m[r][c] = 1;
            output.pop_back();
        }
        if(r-1>=0 && m[r-1][c]){
            output.push_back('U');
            m[r][c] = 0;
            subSequence(m, n, r-1, c, result, output);
            m[r][c] = 1;
            output.pop_back();
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        if(m[0][0]==0 || m[n-1][n-1]==0) return result;
        string output;
        subSequence(m,n,0,0,result, output);
        return result;
    }
};

int main(){
    cout<<"checkpoint 1"<<endl;
    Solution s;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    cout<<"checkpoint 2"<<endl;
    vector<string> result = s.findPath(m, 4);
    cout<<"checkpoint 3"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}