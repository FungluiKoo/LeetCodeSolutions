#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(k,0)));
        dp[0][0][grid[0][0]%k] = 1;
        for(int j=1; j<c; ++j){
            for(int b=0; b<k; ++b){
                dp[0][j][(b+grid[0][j])%k] = dp[0][j-1][b];
            }
        }
        for(int i=1; i<r; ++i){
            for(int b=0; b<k; ++b){
                dp[i][0][(b+grid[i][0])%k] = dp[i-1][0][b];
            }
            for(int j=1; j<c; ++j){
                for(int b=0; b<k; ++b){
                    dp[i][j][(b+grid[i][j])%k] = (dp[i][j-1][b] + dp[i-1][j][b]) % 1000000007;
                }
            }
        }
        return dp[r-1][c-1][0];
    }
};