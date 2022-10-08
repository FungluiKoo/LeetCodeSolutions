using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x^y, result = 0;
        while(a){
            if(a&0b1){++result;}
            a >>= 1;
        }
        return result;
    }
};