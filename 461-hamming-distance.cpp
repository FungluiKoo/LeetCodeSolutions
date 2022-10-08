using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x^y, result = 0;
        while(a){
            result += (a&0b1);
            a >>= 1;
        }
        return result;
    }
};