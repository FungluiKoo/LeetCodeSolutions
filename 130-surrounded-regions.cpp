#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        queue<pair<int,int>> Q;
        for(int j=0; j<c; ++j){
            if(board[0][j]=='O'){board[0][j]='V';Q.push({0,j});}
        }
        if(r>1){
            for(int j=0; j<c; ++j){
                if(board[r-1][j]=='O'){board[r-1][j]='V';Q.push({r-1,j});}
            }
            for(int i=1; i<r-1; ++i){
                if(board[i][0]=='O'){board[i][0]='V';Q.push({i,0});}
                if(c>1 && board[i][c-1]=='O'){board[i][c-1]='V';Q.push({i,c-1});}
            }
        }
        while(!Q.empty()){
            auto [x,y] = Q.front();
            Q.pop();
            vector<pair<int,int>> neighbors = {{x-1,y},{x,y-1},{x,y+1},{x+1,y}};
            for(auto [i,j]:neighbors){
                if(i>=0 && i<r && j>=0 && j<c && board[i][j]=='O'){
                    board[i][j]='V';
                    Q.push({i,j});
                }
            }
        }
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='V'){
                    board[i][j]='O';
                }
            }
        }
    }
};