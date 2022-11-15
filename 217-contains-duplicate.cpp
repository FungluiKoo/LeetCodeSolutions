#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hs;
        for(auto x: nums){
            if(hs.count(x)){return true;}
            hs.insert(x);
        }
        return false;
    }
};