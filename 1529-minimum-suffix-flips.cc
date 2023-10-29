#include <string>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        char prev = '0';
        int count = 0;
        for(auto c : target) {
            if (c != prev) {
                ++count;
                prev = c;
            }
        }
        return count;
    }
};