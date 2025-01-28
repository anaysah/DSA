#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> m_set;
        unordered_set<int> n_set;

        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    m_set.insert(i); n_set.insert(j);
                    matrix[i][j]=0;
                    for(int temp=1; temp<=i; temp++){
                            if(matrix[i-temp][j] != 0)matrix[i-temp][j]=0;
                            else break;
                        }
                    for(int temp=1; temp<=j; temp++){
                        if(matrix[i][j-temp] != 0)matrix[i][j-temp]=0;
                        else break;
                    }
                }
                else if(m_set.find(i)!=m_set.end() || n_set.find(j)!=n_set.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    
}