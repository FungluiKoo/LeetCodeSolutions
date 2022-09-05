#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int max_len = 0;
        for(auto &word: wordDict){
            dict.insert(word);
            max_len = max(int(word.length()),max_len);
        }
        const int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; ++i){
            for(int j=max(i-max_len,0); j<i; ++j){
                if(dp[j] && dict.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    string s = "leetcode";
    vector<string> wordbank = {"leet","code"};
    cout << sol.wordBreak(s, wordbank) << endl;
    return 0;
}