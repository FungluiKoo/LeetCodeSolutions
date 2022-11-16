#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for(auto ch: s){
            ++cnt[ch];
        }
        int result = 0, hasodd = 0;
        for(auto [ch, v]: cnt){
            if(v%2){hasodd = 1;}
            result += (v & (-2));
        }
        return result + hasodd;
    }
};