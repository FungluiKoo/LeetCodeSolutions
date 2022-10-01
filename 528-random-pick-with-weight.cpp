#include <algorithm>
#include <random>
#include <vector>

using namespace std;

class Solution1 {
private:
    discrete_distribution<> dist;
    mt19937 gen;
public:
    Solution(vector<int>& w): dist(w.begin(),w.end()) {
        gen.seed(time(0));
    }
    
    int pickIndex() {
        return dist(gen);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

class Solution2 {
private:
    vector<int> cdf;
    int s;
public:
    Solution(vector<int>& w){
        partial_sum(w.begin(), w.end(), cdf.begin());
        s = cdf.back();
    }
    
    int pickIndex() {
        return lower_bound(cdf.begin(),cdf.end(),rand()%s) - cdf.begin();
    }
};