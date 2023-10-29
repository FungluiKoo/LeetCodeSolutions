#include <vector>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>sx && ty>sy){
            if(tx>ty){tx%=ty;}
            else{ty%=tx;}
        }
        return tx>=sx && ty>=sy && (tx-sx)%ty==0 && (ty-sy)%tx==0;
    }
};