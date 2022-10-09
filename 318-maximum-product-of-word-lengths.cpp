#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int32_t, int> hs;
        for(const auto &word: words){
            int32_t mask = 0;
            for(auto ch: word){
                mask |= (0b1 << (ch-'a'));
            }
            hs[mask] = max(hs[mask], int(word.length()));
        }

        int result = 0;
        vector<pair<int32_t,int>> kv(hs.begin(),hs.end());
        for(int i=0; i<kv.size()-1; ++i){
            for(int j=i+1; j<kv.size(); ++j){
                if((kv[i].first & kv[j].first)==0){
                    result = max(kv[i].second * kv[j].second, result);
                }
            }
        }
        return result;
    }
};