#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()){return "";}
        vector<short> cnt(64,0);
        bitset<64> flag;
        for(auto ch:t){
            ++cnt[ch-'A'];
            flag.set(ch-'A');
        }
        int left=0, right=0, result_left=0, window = INT16_MAX;
        for(; right<s.length(); ++right){
            if(--cnt[s[right]-'A'] <=0){
                flag.reset(s[right]-'A');
            }
            while(left<right && cnt[s[left]-'A']<0){
                ++cnt[s[left++]-'A'];
            }
            if(flag.none() && right-left+1 < window){ // a good window
                result_left = left;
                window = right-left+1;
            }
        }
        return flag.any() ? "" : s.substr(result_left, window);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("a", "b") << endl;
    return 0;
}