#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution{ // BFS
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> isPacific(r,vector<bool>(c,false));
        vector<vector<bool>> isAtlantic(r,vector<bool>(c,false));
        vector<vector<int>> result;
        queue<pair<int,int>> Q;
        // isPacific
        isPacific[0][0]=true;
        for(int j=1; j<c; ++j){
            isPacific[0][j]=true;
            Q.push({0,j});
        }
        for(int i=1; i<r; ++i){
            isPacific[i][0]=true;
            Q.push({i,0});
        }
        while(!Q.empty()){
            auto [i,j] = Q.front();
            Q.pop();
            vector<pair<int,int>> neighbors = {{i-1,j},{i,j-1},{i,j+1},{i+1,j}};
            for(auto [x,y]:neighbors){
                if(x>=0 && x<r && y>=0 && y<c && heights[i][j]<=heights[x][y] && !isPacific[x][y]){
                    isPacific[x][y] = true;
                    Q.push({x,y});
                }
            }
        }
        // isAtlantic
        isAtlantic[r-1][c-1]=true;
        for(int j=c-2; j>=0; --j){
            isAtlantic[r-1][j]=true;
            Q.push({r-1,j});
        }
        for(int i=r-2; i>=0; --i){
            isAtlantic[i][c-1]=true;
            Q.push({i,c-1});
        }
        while(!Q.empty()){
            auto [i,j] = Q.front();
            Q.pop();
            vector<pair<int,int>> neighbors = {{i-1,j},{i,j-1},{i,j+1},{i+1,j}};
            for(auto [x,y]:neighbors){
                if(x>=0 && x<r && y>=0 && y<c && heights[i][j]<=heights[x][y] && !isAtlantic[x][y]){
                    isAtlantic[x][y] = true;
                    Q.push({x,y});
                }
            }
        }
        // result
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(isPacific[i][j] && isAtlantic[i][j])
                result.push_back({i,j});
            }
        }
        return result;
    }
};

class Solution_Incorrect {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> isPacific(r,vector<bool>(c,false));
        vector<vector<bool>> isAtlantic(r,vector<bool>(c,false));
        vector<vector<int>> result;
        // initialization
        for(int j=0; j<c; ++j){isPacific[0][j]=true; isAtlantic[r-1][j]=true;}
        for(int i=0; i<r; ++i){isPacific[i][0]=true; isAtlantic[i][c-1]=true;}
        // isPacific
        for(int i=1; i<r; ++i){
            for(int j=1; j<c; ++j){
                if((isPacific[i-1][j]&&heights[i][j]>=heights[i-1][j])\
                    || (isPacific[i][j-1]&&heights[i][j]>=heights[i][j-1])\
                    ){isPacific[i][j]=true;}
            }
        }
        for(int i=r-1, j=c-2; j>0; --j){
            if(isPacific[i][j+1] && heights[i][j]>=heights[i][j+1]){
                isPacific[i][j] = true;
            }
        }
        for(int i=r-2; i>0; --i){
            int j=c-1;
            if(isPacific[i+1][j] && heights[i][j]>=heights[i+1][j]){
                isPacific[i][j] = true;
            }
            for(j=c-2; j>0; --j){
                if(
                    (isPacific[i+1][j] && heights[i][j]>=heights[i+1][j]) ||
                    (isPacific[i][j+1] && heights[i][j]>=heights[i][j+1])
                ){
                    isPacific[i][j] = true;
                }
            }
        }
        // isAtlantic
        for(int i=r-2; i>=0; --i){
            for(int j=c-2; j>=0; --j){
                if(
                    (isAtlantic[i+1][j] && heights[i][j]>=heights[i+1][j]) ||
                    (isAtlantic[i][j+1] && heights[i][j]>=heights[i][j+1])
                ){
                    isAtlantic[i][j] = true;
                }
            }
        }
        for(int i=0, j=1; j<c; ++j){
            if(isAtlantic[i][j-1] && heights[i][j]>=heights[i][j-1]){
                isAtlantic[i][j] = true;
            }
        }
        for(int i=1; i<r; ++i){
            int j=0;
            if(isAtlantic[i-1][j] && heights[i][j]>=heights[i-1][j]){
                isAtlantic[i][j] = true;
            }
            for(j=1; j<c; ++j){
                if(
                    (isAtlantic[i-1][j] && heights[i][j]>=heights[i-1][j]) ||
                    (isAtlantic[i][j-1] && heights[i][j]>=heights[i][j-1])
                ){
                    isAtlantic[i][j] = true;
                }
            }
        }
        // result
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(isPacific[i][j] && isAtlantic[i][j])
                result.push_back({i,j});
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> heights = {{1,2},{2,1}};
    auto result = sol.pacificAtlantic(heights);
    return 0;
}