#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//LeetCode 155. Min Stack
//very easy soltion just make a prefix array of min values
// or you can make pair like i did, you can store the min value upto that point

//this a space O(n) solution
//but you can encode the min value in the value itself
//see the other code file for that solution

class MinStack {
private:
    vector<pair<int,int>>st={}; //[[value, min_upto_this_point],...]

public:
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int, int>p = {val,val}; //[value, min_upto_this_point]
        if(st.size()>=1)
            p.second = min(st[st.size()-1].second, val);

        cout<<p.first<<" "<<p.second<<endl;
        st.push_back(p);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1].first;
    }
    
    int getMin() {
        return st[st.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    cout<<"Start"<<endl;
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(1);
    obj->push(-4);
    obj->push(0);
    obj->push(-1);
    obj->push(4);
    obj->push(2);
    obj->push(3);
    obj->push(-17);
    cout<<endl;
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}