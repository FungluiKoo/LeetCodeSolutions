#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occur;
        int result = 0, prev = 0, n = s.length();
        for(int i=0; i<n; ++i){
            if(occur.count(s[i])==0){
                occur.insert(s[i]);
            }else{
                result = max(result, i-prev);
                while(s[prev]!=s[i]){
                    occur.erase(s[prev]);
                    ++prev;
                }
                ++prev;
            }
        }
        result = max(result, n-prev);
        return result;
    }
};