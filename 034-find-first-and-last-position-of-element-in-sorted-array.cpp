#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto result = equal_range(nums.cbegin(), nums.cend(), target);
        int left = result.first-nums.cbegin();
        int right = result.second-nums.cbegin();
        if(left==right){return {-1,-1};}
        else{return {left, right-1};}
    }
};