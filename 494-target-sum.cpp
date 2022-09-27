#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if(target>sum || target<-sum){return 0;}
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,0));
        dp[0][sum+nums[0]] += 1;
        dp[0][sum-nums[0]] += 1;
        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<=2*sum; ++j){
                if(j>=nums[i]){
                    dp[i][j] += dp[i-1][j-nums[i]];
                }
                if(j<=2*sum-nums[i]){
                    dp[i][j] += dp[i-1][j+nums[i]];
                }
            }
        }
        return dp[nums.size()-1][sum+target];
    }
};