#include <bitset>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k){
        if(k<=0 || s.length()==0){return 0;}
        vector<short> cnt(128,0);
        bitset<128> flag;
        int result = 0;
        for(int left = 0, right = 0; right<s.length(); ++right){
            if(++cnt[s[right]]>0){flag.set(s[right]);}
            while(left<right && flag.count()>k){
                if(--cnt[s[left]]==0){flag.reset(s[left]);}
                ++left;
            }
            if(right-left+1>result){result=right-left+1;}
        }
        return result;
    }
};