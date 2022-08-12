#include <climits>
#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int lives = 1;
        auto n = nums.size();
        nums.insert(nums.begin(), INT_MIN);
        for (size_t i = 1; i<n; ++i){
            if(nums[i] > nums[i+1]){
                if(--lives < 0){
                    return false;
                }else{
                    if(nums[i+1]<nums[i-1]){
                        nums[i+1] = nums[i];
                    }else{
                        nums[i] = nums[i-1];
                    }
                }
            }
        }
        return true;
    }
};