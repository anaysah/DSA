#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//Leetcode 735. Asteroid Collision
//so this my own solution which i came up with after knowing that this is a stack problem

// this problem is like paranthesis problem
// we just have to pop every time when last two elements are opposite sign specially when right is negative and left is positive

//pop two elements from the last and push one element according to these conditions
// if right is greater than left then push right
// if left is greater than right then push left

// if both are equal then we have already poped two elements so no need to push anything

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n= asteroids.size();

        for(int i=0; i<n; i++){
            st.push_back(asteroids[i]);
            while(st.size()>=2 && st[st.size()-2]>0 && st[st.size()-1]<0){
                int left_astoroid = st[st.size()-2];
                int right_astoroid =  st[st.size()-1];
                st.pop_back();
                if( abs(right_astoroid) > abs(left_astoroid))
                    st[st.size()-1] = right_astoroid;
                else if(abs(right_astoroid) == abs(left_astoroid))
                    st.pop_back();
                else st[st.size()-1] = left_astoroid;
            }
        }
        return st;
    }
};

void testAsteroidCollision(vector<int>& asteroids) {
    Solution sol;
    vector<int> result = sol.asteroidCollision(asteroids);
    cout << "The result is: ";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> asteroids = {5, 10, -5};
    testAsteroidCollision(asteroids);

    // asteroids = {8, -8};
    // testAsteroidCollision(asteroids);

    //some important test cases
    // [4,2,8,5,6,-7]
    // [4,2,-8,5,6,-7]
    // [4,2,-8,5,6,-2]
    // [4,2,8,5,6,-2]
    // [4,2,8,5,6,-8]
    
}