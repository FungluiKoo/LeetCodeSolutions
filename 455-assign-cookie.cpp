#include <algorithm>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        auto child = g.cbegin();
        auto cookie = s.cbegin();
        while(cookie!=s.cend() && child!=g.cend()){
            if(*cookie >= *child){ //content
                ++child;
            }
            ++cookie;
        }
        return (child-g.cbegin());
    }
};