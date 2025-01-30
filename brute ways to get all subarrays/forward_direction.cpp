#include <iostream>
#include <vector>
using namespace std;

// only the first two loops serve the purpose of getting all the subarrays
// the third loop is just for printing the subarray

void print_subarrays(vector<int> arr){
    for(int i = 0; i<arr.size();i++){
        for(int j = i; j<arr.size();j++){


            for(int k = i; k<=j;k++){
                cout << arr[k] << " ";
            }
            cout << endl;



        }
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    print_subarrays(arr);
    return 0;
}