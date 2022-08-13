#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string best = "";
        for(auto word:dictionary){
            int it = 0;
            bool success = true;
            for(auto ch:word){
                while(it<s.length()&&s[it]!=ch){
                    ++it;
                }
                if(it>=s.length()){
                    success = false;
                    break;
                }
                ++it;
            }
            if(success && (word.length()>best.length()\
                || (word.length()==best.length() && word<best) )){
                best = word;
            }
        }
        return best;
    }
};