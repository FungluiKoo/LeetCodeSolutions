#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> heights;
        for(auto &bldg: buildings){
            heights.push_back({bldg[0], -bldg[2]});
            heights.push_back({bldg[1], bldg[2]});
        }
        sort(heights.begin(), heights.end());
        multiset<int> ms;
        ms.insert(0);
        vector<vector<int>> result;
        int prev = 0;
        for(auto &h: heights){
            if(h.second<0){
                ms.insert(-h.second);
            }else{
                ms.erase(ms.find(h.second));
            }
            auto curr = *(ms.rbegin());
            if(prev!=curr){
                result.push_back({h.first, curr});
                prev = curr;
            }
        }
        return result;
    }
};