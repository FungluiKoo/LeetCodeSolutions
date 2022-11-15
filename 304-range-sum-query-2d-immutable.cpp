#include <vector>

using namespace std;

class NumMatrix {
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
private:
    vector<vector<int>> ps;
public:
    NumMatrix(vector<vector<int>>& matrix) : ps(matrix.size()+1, vector<int>(matrix[0].size()+1, 0)) {
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ps[row2+1][col2+1] - ps[row2+1][col1] - ps[row1][col2+1] + ps[row1][col1];
    }
};

