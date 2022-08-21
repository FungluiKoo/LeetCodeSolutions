#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int r;
    int c;
    vector<vector<char>> *board;
    vector<vector<bool>> visited;
    string word;
public:
    bool helper(int x0, int y0){
        stack<pair<int,int>> S;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->r = board.size();
        this->c = board[0].size();
        this->board = &board;
        this->visited.resize(r, vector<bool>(c,false));
        this->word = word;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(helper(i,j)){return true;}
            }
        }
        return false;
    }
};