#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        else if(n==2){return max(nums[0], nums[1]);}
        vector<int> dp(n, 0); 
        // allows robbing nums[0]
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n-1; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        auto allow = dp[n-2];
        // forbids robbing nums[0]
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2; i<n-1; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return max(allow, dp[n-3]+nums[n-1]);
    }
};