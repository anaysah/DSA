#include <iostream>
#include <vector>
using namespace std;

// only the first two loops serve the purpose of getting all the subarrays
// the third loop is just for printing the subarray

void printSubarrays(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >=0 ; j--) {


            for (int k = j; k <= i; ++k) {
                cout << arr[k] << " ";
            }
            cout << std::endl;


        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    printSubarrays(arr);
    return 0;
}