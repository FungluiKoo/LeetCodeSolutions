#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        for(int i=n-2; i>=0; --i){
            int j = i+1;
            while(temperatures[i]>=temperatures[j] && result[j]>0){
                j += result[j];
            }
            result[i] = (temperatures[i]<temperatures[j] ? j-i : 0);
        }
        return result;
    }
};