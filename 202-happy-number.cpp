#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n<1){return false;}
        unordered_set<int> s;
        while(true){
            if(n==1){return true;}
            if(s.count(n)){return false;}
            s.insert(n);
            int tmp = 0;
            while(n){
                tmp += (n%10)*(n%10);
                n /= 10;
            }
            n = tmp;
        }
    }
};
