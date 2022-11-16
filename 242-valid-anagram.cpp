#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for(auto ch: s){
            ++cnt[ch];
        }
        for(auto ch: t){
            --cnt[ch];
        }
        for(auto [ch, v]: cnt){
            if(v){return false;}
        }
        return true;
    }
};