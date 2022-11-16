#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> f1, f2;
        for(int i=0; i<s.length(); ++i){
            if(f1.count(s[i])!=f2.count(t[i]) ||
                (f1.count(s[i]) && f1[s[i]]!=f2[t[i]])
            ){
                return false;
            }
            if(f1.count(s[i])==0){
                f1[s[i]] = i;
                f2[t[i]] = i;
            }
        }
        return true;
    }
};