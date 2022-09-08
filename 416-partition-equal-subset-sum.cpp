#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto s = accumulate(nums.begin(), nums.end(), 0);
        if(s%2){return false;}
        else{s/=2;}
        vector<bool> dp(s+1,false);
        dp[0] = true;
        for(int i=0; i<nums.size(); ++i){
            for(int w=s; w>=nums[i]; --w){
                dp[w] = dp[w] || dp[w-nums[i]];
            }
            if(dp[s]){return true;}
        }
        return false;
    }
};