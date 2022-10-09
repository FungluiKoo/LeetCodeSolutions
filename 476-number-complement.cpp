#include <vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned i=0u;
        while(num>>i){++i;}
        return num^((1u<<i)-1u);
    }
};