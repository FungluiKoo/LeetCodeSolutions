#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1; i<n; ++i){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }else{
                auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};