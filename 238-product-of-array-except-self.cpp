#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int prod=1, i=0; i<n; ++i){
            left[i] = prod;
            prod *= nums[i];
        }
        for(int prod=1, i=n-1; i>=0; --i){
            right[i] = prod;
            prod *= nums[i];
        }
        for(int prod=1, i=0; i<n; ++i){
            left[i] *= right[i];
        }
        return left;
    }
};