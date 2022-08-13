#include <cmath>

using namespace std;

class Solution{
public:
    bool judgeSquareSum(int c){
        unsigned long left = 0, right = floor(sqrt(c));
        while(left<=right){
            auto sos = left*left + right*right;
            if(sos > (unsigned long)c){
                right--;
            }else if(sos < c){
                left++;
            }else{
                return true;
            }
        }
        return false;
    }
};
