#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//any number can be easily expresed in power of 2
//lets say 53
//if we take LCM of 53 by removing reminders ( or you can say that we have to find binary of 53)
// 53 base 10 = 110101 base 2
// 53 = (1 * 2^5) + (1 * 2^4) + (0 * 2^3) + (1 * 2^2) + (0 * 2^1) + (1 * 2^0) (we got this by taking LCM of 53)
// 53 = 32 + 16 + 4 + 1 = 53

// so lets say we want to find 3^53
// we can express 3^53 as 3^(32+16+4+1) = 3^32 * 3^16 * 3^4 * 3^1

int right_to_left(int base, int exp){
    int result = 1; 
    int current_base = base;

    while(exp>0){
        if(exp%2==1){
            result = result*current_base;
        }
        current_base = current_base*current_base;
        exp = exp/2;
    };

    return result;

}

int main(){
    cout << "Hello World" << endl;
    cout << right_to_left(3, 9) << endl;  // 19683
    return 0;
}