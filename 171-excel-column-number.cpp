#include <string>

class Solution {
private:
    int char2int(char ch){
        return ch-'A'+1;
    }
public:
    int titleToNumber(std::string columnTitle) {
        int result = 0;
        for(auto ch : columnTitle){
            result *= 26;
            result += char2int(ch);
        }
        return result;
    }
};