using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for(int i=5; i<=n; i+=(i<<2)){
            cnt += n/i;
        }
        return cnt;
    }
};