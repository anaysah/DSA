#include <iostream>
#include <vector>
using namespace std;

//LeetCode48. Rotate Image

// transpose matrix then reverse all rows
// remember to do the transpose for the diagonal half matrix only
// because the other half will be swapped again

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0; i<n; i++){
            for(int start=0, last=n-1; start<=last; start++,last--){
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][last];
                matrix[i][last] = temp;
            }
        }

    }
};
