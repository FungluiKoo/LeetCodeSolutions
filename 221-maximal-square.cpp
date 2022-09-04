#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;
        auto prev = new int[c](); // initialized to zeros
        auto curr = new int[c];
        for(int i=0; i<r; ++i){
            curr[0] = (matrix[i][0]=='0') ? 0 : 1;
            ans = max(curr[0],ans);
            for(int j=1; j<c; ++j){
                if(matrix[i][j]=='0'){
                    curr[j] = 0;
                }else{
                    if(curr[j-1]!=prev[j]){
                        curr[j] = min(curr[j-1], prev[j])+1;
                    }else{
                        curr[j] = min(prev[j-1], prev[j])+1;
                    }
                }
                ans = max(curr[j],ans);
            }
            auto temp = prev;
            prev = curr;
            curr = temp;
        }
        delete[] prev;
        delete[] curr;
        return ans*ans;
    }
};