#include <iostream>
#include <vector>

using namespace std;
void printVector(vector<char> v)
{
    cout<<"[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<"] ";
    cout << endl;
}


void printVector2D(vector<vector<char>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i)
        if (board[i][col] == c || board[row][i] == c ||
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
        return true;
    }
    bool subSequence(vector<vector<char>>& board, int r, int c){
        while(board[r][c]!='.'){
            c++;
            if(c/9==1){
                c=0;r++;
            }
            if(r>=9) {
                return true;
            }
        }

        bool result = false;
        for(int i=1;i<=9;i++){
            if(isValid(board, r, c , char(48+i))){
                board[r][c] = char(48+i);
                result = subSequence(board, r, c);
                if(result==false) board[r][c] = '.';
                else break;
            }
        }
        return result;
    }

    void solveSudoku(vector<vector<char>>& board) {
        subSequence(board, 0, 0);
        return;
    }
};

int main(){
    //print welcome
    cout << "Welcome to Sudoku Solver!" << endl;
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '6', '7', '8', '9', '.', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '.', '4', '8', '5', '6'},
        {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };
    s.solveSudoku(board);
    printVector2D(board);
    return 0;
}