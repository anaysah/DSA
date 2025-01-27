#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// lets say 53
// if we take LCM of 53 by 2 by leaving the remainder
// 53/2 = 26 remainder 1
// 26/2 = 13 remainder 0
// 13/2 = 6 remainder 1
// 6/2 = 3 remainder 0
// 3/2 = 1 remainder 1
// 1/2 = 0 remainder 1
// so the binary of 53 is 110101

// x^53 = (((((1^2*x)^2*x)^2)^2*x)^2)^2 * x


string decimal_to_binary(int n) {
    if (n == 0) return "0";  // Handle the case when n is 0

    string result = "";
    while (n > 0) {
        result = to_string(n % 2) + result;  // Prepend remainder to the result
        n /= 2;  // Divide n by 2
    }
    return result;
}


int left_to_right(int base, int exp){
    int result = 1;
    string binary = decimal_to_binary(exp);
    cout << binary << endl;
    for(int i =0; i<binary.size();i++){
        result = result*result;
        if(binary[i]=='1'){
            cout << "running: 1"<< endl;
            result = result*base;
        }
    }
    return result;
}

int main(){
    cout << left_to_right(3, 9) << endl;  // 1024
    // use math function to check the result
    cout << pow(3, 9) << endl;  // 1024
    return 0;
}