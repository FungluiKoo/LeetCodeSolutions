#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=0; i<strs.size(); ++i){
            int cnt_0 = count(strs[i].begin(), strs[i].end(), '0');
            int cnt_1 = strs[i].length() - cnt_0;
            for(int a=m; a>=cnt_0; --a){
                for(int b=n; b>=cnt_1; --b){
                    dp[a][b] = max(dp[a-cnt_0][b-cnt_1]+1, dp[a][b]);
                }
            }
        }
        return dp[m][n];
    }
};