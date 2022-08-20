#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        string result = s.substr(0,1);
        vector<vector<bool>> dp(N,vector<bool>(N,false));
        for(int i=0; i<N; ++i){dp[i][i] = true;}
        for(int i=1; i<N; ++i){
            if(s[i-1]==s[i]){
                dp[i-1][i] = true;
                if(result.length()<2){result = s.substr(i-1,2);}
            }
        }
        for(int L=2; L<N; ++L){
            for(int i=L; i<N; ++i){
                if(s[i-L]==s[i] && dp[i-L+1][i-1]){
                    dp[i-L][i]=true;
                    if(result.length()<L+1){result = s.substr(i-L,L+1);}
                }
            }
        }
        return result;
    }
};