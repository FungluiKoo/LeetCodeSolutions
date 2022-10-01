#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber){
            int x = columnNumber%26;
            if(x==0){x=26;}
            char ch = 'A'+(x-1);
            result = ch + result;
            columnNumber -= x;
            columnNumber /= 26;
        }
        return result;
    }
};