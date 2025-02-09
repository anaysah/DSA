#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// LeetCode 901. Online Stock Span
// monotonic stack

// stack will have from greatest to smallest
//becuase we need just first greater element on left side
// so we can pop all the elements which are smaller than current element
// and then we can get the first greater element on left side
// and then we can calculate the span
// and then we can push the current element to stack
// and then we can return the span

class StockSpanner {
private:
    stack<pair<int, int>> st; //[index, value]
    int current_index = -1;
public:
    StockSpanner() {
        st.push({current_index,INT_MAX});
    }
    
    int next(int price) {
        current_index++;
        // int count=0;
        while(st.size()!=1 && st.top().second <= price){
            st.pop();
            // count++;
        }

        int last_index = st.top().first;
        st.push({current_index, price});

        return current_index - last_index;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main(){
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;
    return 0;

//some important test cases
// ["StockSpanner","next","next","next","next","next","next","next"]
// [[],[100],[80],[60],[70],[60],[75],[85]]
// ["StockSpanner","next","next","next","next","next","next","next","next","next","next","next","next","next","next"]
// [[],[1],[3],[6],[10],[8],[9],[2],[13],[7],[9],[2],[5],[3],[9]]
// ["StockSpanner","next"]
// [[],[199]]

}