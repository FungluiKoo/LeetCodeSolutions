#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> repres;
        for (auto x : arr) {
            int cnt = 0, num = x;
            while(x) {
                cnt += x & 1;
                x >>= 1;
            }
            repres.push_back({cnt, num});
        }
        sort(repres.begin(), repres.end());
        vector<int> res;
        for (auto [cnt, num] : repres) {
            res.push_back(num);
        }
        return res;
    }
};