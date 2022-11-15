#include <queue>

using namespace std;

class MyStack {
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
private:
    queue<int> Q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n = Q.size();
        Q.push(x);
        for(int i=0; i<n; ++i){
            auto elem = Q.front();
            Q.pop();
            Q.push(elem);
        }
    }
    
    int pop() {
        auto x = Q.front();
        Q.pop();
        return x;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

