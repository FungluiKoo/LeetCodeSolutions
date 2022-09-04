#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> dp(c, __INT_MAX__);
        dp[0] = 0;
        for(int i=0; i<r; ++i){
            dp[0] += grid[i][0];
            for(int j=1; j<c; ++j){
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
            }
        }
        return dp[c-1];
    }
};