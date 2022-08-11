#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int prev_flower = -2;
        for(int i=0; i<flowerbed.size(); ++i){
            if(flowerbed[i]==1){
                cnt += (i-prev_flower-2)/2;
                prev_flower = i;
            }
        }
        cnt += (flowerbed.size()-prev_flower-1)/2;
        return cnt>=n;
    }
};