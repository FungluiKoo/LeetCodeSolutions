#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for(auto x:nums){
            if(x!=0){arr.push_back(x);}
        }
        arr.push_back(1);
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=2; j<n; ++j){
            for(int i=j-2; i>=0; --i){
                for(int k=i+1; k<j; ++k){
                    dp[i][j] = max(dp[i][j],\
                                arr[i]*arr[k]*arr[j]+dp[i][k]+dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};