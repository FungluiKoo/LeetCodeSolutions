#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    int r;
    int c;
    string word;
    vector<vector<char>> board;

    bool helper(int x, int y, int level){
        if(level==word.length()){return true;}
        auto tmp = board[x][y];
        board[x][y] = '#';
        vector<pair<int,int>> neighbors = {{x-1,y}, {x,y-1}, {x,y+1}, {x+1,y}};
        for(auto [i,j]:neighbors){
            if(board[i][j]==word[level] && helper(i,j,level+1)){
                return true;
            }
        }
        board[x][y] = tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // precheck
        if(word.length()==0){return true;}
        
        this->r = board.size();
        this->c = board[0].size();
        
        unordered_map<char,int> cnt;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                ++cnt[board[i][j]];
            }
        }
        for(auto &ch:word){
            if(--cnt[ch]<0){return false;}
        }

        // initialize board
        this->word = word;
        this->board.resize(r+2, vector<char>(c+2, '#'));
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                this->board[i+1][j+1] = board[i][j];
            }
        }

        // dfs
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j]==word[0] && helper(i+1,j+1,1)){return true;}
            }
        }
        return false;
    }
};


class Solution2 {
private:
    int r;
    int c;
    vector<vector<char>> *board;
    vector<vector<bool>> visited;
    string word;

    bool helper(int x, int y, int level){
        if(level==word.length()){return true;}
        visited[x][y] = true;
        vector<pair<int,int>> neighbors = {{x-1,y}, {x,y-1}, {x,y+1}, {x+1,y}};
        for(auto [i,j]:neighbors){
            if(i>=0 && i<r && j>=0 && j<c && !visited[i][j] \
            && (*board)[i][j]==word[level] && helper(i,j,level+1)){
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0){return true;}
        this->r = board.size();
        this->c = board[0].size();
        this->board = &board;
        this->visited.resize(r, vector<bool>(c,false));
        this->word = word;

        // precheck
        unordered_map<char,int> cnt;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                ++cnt[board[i][j]];
            }
        }
        for(auto &ch:word){
            if(--cnt[ch]<0){return false;}
        }

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j]==word[0] && helper(i,j,1)){return true;}
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    return 0;
}