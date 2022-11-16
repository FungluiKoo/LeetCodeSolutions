#include <string>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), result = 0;
        char prev_ch = s[0];
        int i = 1, prev_cnt = 1;
        while(i<n && s[i]==prev_ch){++i;++prev_cnt;}
        while(i<n){
            char curr_ch = s[i];
            ++i;
            int curr_cnt = 1;
            while(i<n && s[i]==curr_ch){++i; ++curr_cnt;}
            result += min(prev_cnt, curr_cnt);
            prev_ch = curr_ch;
            prev_cnt = curr_cnt;
        }
        return result;
    }
};