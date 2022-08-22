#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    int r;
    int c;
public:
    int shortestBridge(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        // find a land
        stack<pair<int,int>> S;
        for(int i=0, found=0; i<r && !found; ++i){
            for(int j=0; j<c && !found; ++j){
                if(grid[i][j]){found = 1; S.push({i,j});}
            }
        }
        // DFS to color this island as "2", color seashore as "3"
        queue<pair<int,int>> Q;
        while(!S.empty()){
            auto [x,y] = S.top();
            S.pop();
            if(grid[x][y]==1){
                grid[x][y]=2;
                vector<pair<int,int>> neighbors = {{x-1,y},{x,y-1},{x,y+1},{x+1,y}};
                for(auto &[i,j]:neighbors){
                    if(i>=0 && i<r && j>=0 && j<c){
                        if(grid[i][j]==1){
                            S.push({i,j});
                        }else if(grid[i][j]==0){
                            grid[i][j] = 3;
                            Q.push({i,j});
                        }
                    }
                }
            }
        }
        // BFS the sea until reaching another land (colored in "1")
        int result = 0;
        while(!Q.empty()){
            ++result; // current distance from the island colored "2"
            for(int i=Q.size(); i>0; --i){
                auto [x,y] = Q.front();
                Q.pop();
                vector<pair<int,int>> neighbors = {{x-1,y},{x,y-1},{x,y+1},{x+1,y}};
                for(auto &[i,j]:neighbors){
                    if(i>=0 && i<r && j>=0 && j<c){
                        if(grid[i][j]==0){
                            grid[i][j] = 3;
                            Q.push({i,j});
                        }else if(grid[i][j]==1){
                            return result;
                        }
                    }
                }
            }            
        }
        return -1;
    }
};

int main(){
    Solution sol;
    return 0;
}