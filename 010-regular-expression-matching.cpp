#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=2; j<=m && p[j-1]=='*'; j+=2){
            dp[0][j] = true;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                dp[i][j] = p[j-1]=='*' ?\
                    dp[i][j-2] || dp[i][j-1] || (dp[i-1][j] && (p[j-2]=='.'||p[j-2]==s[i-1])) :\
                    dp[i-1][j-1] && (p[j-1]=='.'||p[j-1]==s[i-1]);
            }
        }
        return dp[n][m];
    }
};

class Solution2 { // lazy
public:
    bool isMatch(string s, string p) {
        regex re(p);
        return regex_match(s, re);
    }
};