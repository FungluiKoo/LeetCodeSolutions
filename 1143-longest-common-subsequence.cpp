#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> dp(m+1, 0);
        for(int i=1; i<=n; ++i){
            int prev = 0, curr = 0;
            for(int j=1; j<=m; ++j){
                if(text1[i-1]==text2[j-1]){
                    curr = dp[j-1]+1;
                }else{
                    curr = max(dp[j],prev);
                }
                dp[j-1] = prev;
                prev = curr;
            }
            dp[m] = curr;
        }
        return dp[m];
    }
};

int main(){
    Solution sol;
    cout << sol.longestCommonSubsequence("ezupkr","ubmrapg") << endl;
    return 0;
}