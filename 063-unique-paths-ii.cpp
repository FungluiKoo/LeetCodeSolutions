#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<int> dp(c,0);
        if(obstacleGrid[0][0]){
            return 0;
        }else{
            dp[0] = 1;
        }
        for(int i=0; i<r; ++i){
            dp[0] = (obstacleGrid[i][0]==0 && dp[0]==1)? 1:0;
            for(int j=1; j<c; ++j){
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                }else{
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[c-1];
    }
};