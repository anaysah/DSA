#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

//LeetCode 155. Min Stack
//we will try to encode the upto min value in the value itself
//this approach is very hard to come up with
//but this is better approach as we are only using one stack

//i have writtern explantion in the images please look their. their are diagrams also

class MinStack {
private:
    long min;
    stack<long> stack; //directly stack is used instead vector, which is okay

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push(0);
            min = val;
        } else {
            stack.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        
        long pop = stack.top();
        stack.pop();
        
        if (pop < 0) min = min - pop;
    }
    
    int top() {
        long top = stack.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
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