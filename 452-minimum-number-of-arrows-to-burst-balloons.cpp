#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()){
            return 0;
        }
        std::sort(points.begin(), points.end(), \
            [](std::vector<int> a, std::vector<int> b){
                return a[1] <= b[1];
            }
        );
        int x = points[0][1];
        int cnt = 1;
        for (auto iter = points.cbegin(); iter != points.cend(); ++iter){
            if (iter->front() > x){
                x = iter->back();
                ++cnt;
            }
        }
        return cnt;
    }
};