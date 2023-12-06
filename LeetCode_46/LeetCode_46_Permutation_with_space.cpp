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

class Solution {
public:
    void subSequence(vector<int>& nums, int N, vector<int>&output, vector<int>&fqArray,vector<vector<int>>&result){
        

        if(output.size()>=N){
            cout << "run " << "\n" << endl;
            result.push_back(output);
            return;
        }
        int i=0;
        for (i=0; i<N; i+=1){
            if (fqArray[i]){
                output.push_back(nums[i]);
                fqArray[i] = 0;
                // cout << nums[i] << endl;
                printVector(output);
                printVector(fqArray);
                cout << "\n" << endl;
                subSequence(nums, N, output, fqArray, result);
                output.pop_back();
                fqArray[i] = 1;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        vector<int> fqArray(nums.size(), 1);
        subSequence(nums, nums.size(), output, fqArray, result);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = s.permute(nums);
    for(auto i:result){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
