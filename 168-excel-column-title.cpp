#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result = "";
        while(columnNumber>0){
            auto ch = char('A'+(columnNumber-1)%26);
            result = ch + result;
            columnNumber = (columnNumber-1)/26;
        }
        return result;
    }
};