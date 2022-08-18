#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> discovered(grid.size(), vector<bool>(grid[0].size(),false));
        int max_area = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(!discovered[i][j] && grid[i][j]){
                    int curr_area = 0;
                    stack<pair<int,int>> S;
                    S.push({i,j});
                    while(!S.empty()){
                        auto [r, c] = S.top();
                        S.pop();
                        if(!discovered[r][c]){
                            discovered[r][c] = true;
                            ++curr_area;
                            // add neighbors
                            if(r>0 && grid[r-1][c]){S.push({r-1,c});}
                            if(c>0 && grid[r][c-1]){S.push({r,c-1});}
                            if(c<grid[0].size()-1 && grid[r][c+1]){S.push({r,c+1});}
                            if(r<grid.size()-1 && grid[r+1][c]){S.push({r+1,c});}
                        }
                    }
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,0,1,1,1}};
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}