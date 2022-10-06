#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int i = 0;
        while(seats[i]==0){++i;}
        int maxdist = i, prev_person = i;
        for(; i<n; ++i){
            if(seats[i]){
                maxdist = max((i-prev_person)/2, maxdist);
                prev_person = i;
            }
        }
        maxdist = max(n-1-prev_person, maxdist);
        return maxdist;
    }
};