#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        for(auto num: nums){
            hs.insert(num);
        }
        int result = 0;
        while(!hs.empty()){
            auto x = *(hs.begin());
            hs.erase(x);
            int i=x-1;
            for(; hs.contains(i); --i){
                hs.erase(i);
            }
            int j=x+1;
            for(; hs.contains(j); ++j){
                hs.erase(j);
            }
            result = max(result, j-i-1);
        }
        return result;
    }
};