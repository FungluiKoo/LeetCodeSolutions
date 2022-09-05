#include <stack>

using namespace std;


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
private:
    stack<pair<int,int>> S;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(S.empty()){
            S.push({val,val});
        }else{
            auto curr_min = S.top().second;
            S.push({val,min(curr_min,val)});
        }
    }
    
    void pop() {
        S.pop();
    }
    
    int top() {
        return S.top().first;
    }
    
    int getMin() {
        return S.top().second;
    }
};