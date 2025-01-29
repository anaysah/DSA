#include <iostream>
#include <vector>
using namespace std;

//LeetCode 54. Spiral Matrix

// direction and round is important
// direction 1: right, 2: down, 3: left, 4: up
// round is the number of rounds that we have completed or levels that we have completed
// with the hlep of direction we can write code for individual directions
// on each level completed we can reasign the values of i and j to start the next round and can forgate that we had this outer ring in the matrix
// can intialie a vector of size m*n and keep on adding the elements in the vector in the order of spiral matrix



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int direction = 1; int round = 0;
        int i=0, j=0; 
        int m=matrix.size(); int n=matrix[0].size();
        
        vector<int> vec(m*n);
        int vec_i=0; //vector index

        while(vec_i< vec.size()){
            if(direction==1){
                while(j<=n-round-1){
                    // cout << matrix[i][j] << " ";
                    vec[vec_i] = matrix[i][j]; j++; vec_i++;
                }
                direction = 2; j--; i++;
            }
            else if(direction==2){
                while(i<=m-round-1){
                    // cout << matrix[i][j] << " ";
                    vec[vec_i] = matrix[i][j]; i++; vec_i++;
                }
                direction = 3; i--; j--;
            }
            else if(direction==3){
                while(j>=round){
                    // cout << matrix[i][j] << " ";
                    vec[vec_i] = matrix[i][j]; j--; vec_i++;
                }
                direction = 4; j++; i--;
            }
            else if(direction==4){
                while(i>round){
                    // cout << matrix[i][j] << " ";
                    vec[vec_i] = matrix[i][j]; i--; vec_i++;
                }
                direction = 1;
                round++; i=round; j=round;
            }
        }
        cout<<endl;
        return vec;
    }
};

void printSpiralOrder(vector<vector<int>>& matrix) {
    Solution sol;
    vector<int> vec = sol.spiralOrder(matrix);
    
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };
    printSpiralOrder(matrix);

    matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    printSpiralOrder(matrix);

    matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    printSpiralOrder(matrix);

    matrix = {{1, 2, 3},{4, 5, 6}};
    printSpiralOrder(matrix);

    matrix = {{1, 2},{3, 4},{5, 6}};
    printSpiralOrder(matrix);

    matrix = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    printSpiralOrder(matrix);

    return 0;
}