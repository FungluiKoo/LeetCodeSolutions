#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution1 {
public:
    string frequencySort(string s) {
        unordered_map<char,int> cnt;
        for(auto ch:s){++cnt[ch];}
        multimap<int,char> inv;
        for(auto p:cnt){
            inv.insert({p.second,p.first});
        }
        string result;
        for(auto it=inv.rbegin(); it!=inv.rend(); ++it){
            result.append(it->first, it->second);
        }
        return result;
    }
};

class Solution2 {
public:
    string frequencySort(string s) {
        vector<string> cnt(128,"");
        for(auto ch:s){cnt[ch]+=ch;}
        sort(cnt.begin(),cnt.end(),[](const string &a, const string &b){
            return a.length() > b.length();
        });
        string result;
        for(auto substr:cnt){
            result += substr;
        }
        return result;
    }
};