#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto n = nums.size();
        if(n<=1) return true;
        int max_reach = nums[0];
        for(int i=1; i<n; ++i){
            if(max_reach < i) return false;
            max_reach = max(max_reach, i+nums[i]);
        }
        return true;
    }
};