#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        auto median = nums[nums.size()/2];
        int result = 0;
        for(auto num : nums){
            result += abs(num-median);
        }
        return result;
    }
};