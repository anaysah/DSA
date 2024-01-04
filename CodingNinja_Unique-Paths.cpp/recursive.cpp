#include <bits/stdc++.h>
using namespace std;

void f(int m, int n, int c_m, int c_n, int &count){
    if(c_m==(m) && c_n==(n)){
        count++;
        return;
    }
    if(c_n+1<=n)
    f(m, n, c_m, c_n+1, count);
    
    if(c_m+1<=m)
    f(m, n, c_m+1, c_n, count);
}

int uniquePaths(int m, int n) {
    int count = 0;
    f(m, n, 1, 1, count);
    return count;
}

int main(){
    cout<<"done: "<<uniquePaths(4, 2)<<" ans";
}