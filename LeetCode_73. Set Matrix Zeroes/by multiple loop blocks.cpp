#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> m_set;
        set<int> n_set;

        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    m_set.insert(i); n_set.insert(j);
                }
            }
        }

        for(auto i:m_set){
            for(int j=0; j<n; j++) matrix[i][j] = 0;
        }
        for(auto j:n_set){
            for(int i=0; i<m; i++) matrix[i][j] = 0;
        }
    }
};

int main(){
    
}