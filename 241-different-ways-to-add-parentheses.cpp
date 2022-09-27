#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        istringstream iss(expression);
        int num;
        char op;
        iss >> num;
        nums.push_back(num);
        while(iss>>op && iss>>num){
            ops.push_back(op);
            nums.push_back(num);
        }
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        for(int j = 0; j<n; ++j){
            dp[j][j].push_back(nums[j]);
            for(int i = j-1; i>=0; --i){
                for(int k=i; k<j; ++k){
                    for(auto left: dp[i][k]){
                        for(auto right: dp[k+1][j]){
                            switch (ops[k]){
                            case '+':
                                dp[i][j].push_back(left+right);
                                break;
                            case '-':
                                dp[i][j].push_back(left-right);
                                break;
                            case '*':
                                dp[i][j].push_back(left*right);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};