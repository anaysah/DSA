#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    int xi, xii, xiii;
    xi = points[n-1][0];
    xii = points[n-1][1];
    xiii = points[n-1][2];
    
    for(int r=n-2; r>=0; r--){
        int temp[] = {0, 0, 0};
        for(int c=0; c<3; c++){
            int i=0, ii=0, iii=0;

            if(c!=0)
                i = points[r][c] + xi;

            if(c!=1)
                ii = points[r][c] + xii;

            if(c!=2)
                iii = points[r][c] + xiii;

            int m = max(max(i, ii), iii);

            temp[c] = m;
        }
        xi = temp[0];
        xii = temp[1];
        xiii = temp[2];
    }

    return max(max(xi, xii), xiii);
}

int main(){
    vector<vector<int>> points = {{1,2,5},{3,1,1}};
    cout<<ninjaTraining(points.size(), points);

}