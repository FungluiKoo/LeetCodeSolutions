#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalin(string &s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]){return false;}
            ++left;
            --right;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left<right){
            if(s[left]==s[right]){
                ++left;
                --right;
            }else{
                return isPalin(s,left+1,right) || isPalin(s,left,right-1);
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    cout << (sol.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") ? "true" : "false") << endl;
    return 0;
}