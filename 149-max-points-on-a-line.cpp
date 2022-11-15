#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3){return n;}
        int result = 0;
        for(int i=0; i<n-1; ++i){
            unordered_map<double, int> cnt;
            int same_x = 1, same_point = 1;
            for(int j=i+1; j<n; ++j){
                if(points[j][0]!=points[i][0]){
                    ++cnt[(points[j][1]-points[i][1])*1.0/(points[j][0]-points[i][0])];
                }else{
                    ++same_x;
                    if(points[j][1]==points[i][1]){++same_point;}
                }
            }
            for(auto [d,c]: cnt){
                result = max(result, c+same_point);
            }
            result = max(result, same_x);
        }
        return result;
    }
};