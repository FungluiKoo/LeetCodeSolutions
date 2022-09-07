#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // increasing stack
        vector<int> prevsmall(n, -1);
        vector<int> nextsmall(n, n);
        stack<pair<int,int>> ins; // id, value
        for(int i=0; i<n; ++i){
            while(!ins.empty() && ins.top().second>=heights[i]){
                nextsmall[ins.top().first] = i;
                ins.pop();
            }
            prevsmall[i] = ins.empty() ? -1: ins.top().first;
            ins.push({i, heights[i]});
        }
        // calculate largest value at each i
        int result = 0;
        for(int i=0; i<n; ++i){
            result = max((nextsmall[i]-prevsmall[i]-1)*heights[i], result);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}