#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n==0){return m;}
        if(m==0){return n;}
        vector<int> dp(m+1, 0);
        for(int j=1; j<=m; ++j){dp[j] = j;}
        for(int i=1; i<=n; ++i){
            int prev = i;
            for(int j=1; j<=m; ++j){
                int curr = (word1[i-1]==word2[j-1]) ? dp[j-1] : min(prev, dp[j])+1;
                dp[j-1] = prev;
                prev = curr;
            }
            dp[m] = prev;
        }
        return dp[m];
    }
};