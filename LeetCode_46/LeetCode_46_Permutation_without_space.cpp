#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//write a function to print all the elements of a vector
void printVector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//write a function to print 2d vector
void printVector2D(vector<vector<int>> v){
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    void swap(vector<int> &a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    void subSequence(vector<int>& nums, int N, int i, vector<vector<int>>result){
        if(i>=N-1){
            result.push_back(nums);
            return;
        }

        for(int j=i;j<N;j++){
            swap(nums,i, j);
            printVector(nums);
            subSequence(nums, N, i+1, result);
            swap(nums,i, j);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        subSequence(nums, nums.size(), 0, result);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    printVector2D(s.permute(nums));
    return 0;
}