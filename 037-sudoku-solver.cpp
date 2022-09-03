#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<vector<bool>>> sq;

    bool helper(vector<vector<char>>& board, int level){
        if(level==81){ // success
            return true;
        }
        int r = level/9;
        int c = level%9;
        if(board[r][c]!='.'){return helper(board, level+1);}
        for(int x=0; x<9; ++x){
            if(!row[r][x] && !col[c][x] && !sq[r/3][c/3][x]){
                board[r][c] = x+'1';
                row[r][x] = true;
                col[c][x] = true;
                sq[r/3][c/3][x] = true;
                if(helper(board, level+1)){
                    return true;
                }
                board[r][c] = '.';
                row[r][x] = false;
                col[c][x] = false;
                sq[r/3][c/3][x] = false;
            }
        }
        return false;
    }

public:
    Solution() : 
                row(9,vector<bool>(9,false)), 
                col(9,vector<bool>(9,false)), 
                sq(3,vector<vector<bool>>(3,vector<bool>(9,false))){}

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.'){
                    int x = board[i][j]-'1';
                    row[i][x] = true;
                    col[j][x] = true;
                    sq[i/3][j/3][x] = true;
                }
            }
        }
        helper(board, 0);
    }
};

int main(){
    Solution sol;
    return 0;
}