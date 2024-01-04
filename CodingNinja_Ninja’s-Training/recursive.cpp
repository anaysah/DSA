#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003

int f(int n, vector<vector<int>> &points, int r, int p){
    if(r>=n) return 0;

    int i=0, ii=0, iii=0;

    if(p!=0 ){
        i = points[r][0] + f(n, points, r+1, 0);
    }

    if(p!=1){
        ii = points[r][1] + f(n, points, r+1, 1);
    }

    if(p!=2){
        iii = points[r][2] + f(n, points, r+1, 2);
    }

    // cout<< dp[r]<< " ";
    return max(max(i, ii), iii);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n, points, 0, -1);
}

int main(){
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    cout<<ninjaTraining(3, points);

}