#include <algorithm>
#include <vector>

using namespace std;

class NumArray {
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
private:
    vector<int> ps;
public:
    NumArray(vector<int>& nums): ps(nums.size()+1, 0) {
        // partial_sum may not be supported by the compiler
        for(int i=0; i<nums.size(); ++i){
            ps[i+1] = ps[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return ps[right+1] - ps[left];
    }
};
