#include "segment-tree.hh"

using namespace std;


struct MySum{
    int operator()(int a, int b) const{
        return a+b;
    }
};

class NumArray {
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
private:
    segment_tree<int, MySum> st;
public:
    NumArray(vector<int>& nums) : st(nums) {
        
    }
    
    void update(int index, int val) {
        st.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left, right);
    }
};

