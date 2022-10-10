#include <stack>

using namespace std;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
private:
    stack<int> infile, outfile;
    void fill(){
        while(!infile.empty()){
            outfile.push(infile.top());
            infile.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        infile.push(x);
    }
    
    int pop() {
        if(outfile.empty()){fill();}
        int res = outfile.top();
        outfile.pop();
        return res;
    }
    
    int peek() {
        if(outfile.empty()){fill();}
        return outfile.top();
    }
    
    bool empty() {
        return infile.empty() && outfile.empty();
    }
};
