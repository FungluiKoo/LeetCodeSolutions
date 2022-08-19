#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    int k;
    vector<int> nums;
    vector<vector<int>> result;

    void helper(int curr){
        if(nums.size()==k){
            result.push_back(nums);
            return;
        }
        // Option 1: Add curr to nums
        nums.push_back(curr);
        helper(curr+1);
        nums.pop_back();
        // Option 2: Not add curr to nums
        if(n-curr>=k-nums.size()){
            helper(curr+1);
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        helper(1);
        return result;
    }
};

int main(){
    while(true){
        Solution sol;
        int n=1, k=1;
        cin >> n >> k;
        if(n==0 || k==0){break;}
        auto result = sol.combine(n,k);
        cout << result.size() << endl;        
    }
    return 0;
}