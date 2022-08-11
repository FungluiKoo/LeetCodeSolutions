#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), \
            [](std::vector<int> a, std::vector<int> b){
                return a[1] <= b[1];
        });
        int time = INT_MIN;
        int cnt = 0;
        for(auto iter = intervals.cbegin(); iter!=intervals.cend(); ++iter){
            if(iter->front() >= time){
                time = iter->back();
            }else{
                ++cnt;
            }
        }
        return cnt;
    }
};