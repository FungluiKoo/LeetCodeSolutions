#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &result, vector<int>& nums, int level){
        if(level==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int i=level; i<nums.size(); ++i){
            swap(nums[level],nums[i]);
            backtrack(result,nums,level+1);
            swap(nums[level],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }
};