#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        auto n = ratings.size();
        auto left = new short[n];
        auto right = new short[n];
        left[0] = 0;
        for(int i=1; i<n; ++i){
            left[i] = (ratings[i] > ratings[i-1]) ? (left[i-1] + 1) : 0;
        }
        right[n-1] = 0;
        for(int i=n-2; i>=0; --i){
            right[i] = (ratings[i] > ratings[i+1]) ? (right[i+1] + 1) : 0;
        }
        int result = n;
        for(int i=0; i<n; ++i){
            result += int(std::max(left[i], right[i]));
        }
        delete[] left;
        delete[] right;
        return result;
    }
};