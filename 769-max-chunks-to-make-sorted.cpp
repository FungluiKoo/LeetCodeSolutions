#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n<2){return 1;}
        vector<int> leftmax(n,0);
        vector<int> rightmin(n,0);
        int mymax = arr[0];
        leftmax[0] = mymax;
        for(int i=1; i<n; ++i){
            mymax = max(mymax,arr[i]);
            leftmax[i] = mymax;
        }
        int mymin = arr[n-1];
        rightmin[n-1] = mymin;
        for(int i=n-2; i>=0; --i){
            mymin = min(mymin, arr[i]);
            rightmin[i] = mymin;
        }
        int result = 1;
        for(int i=0; i<n-1; ++i){
            if(leftmax[i]<=rightmin[i+1]){++result;}
        }
        return result;
    }
};