#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        unsigned n = nums1.size();
        vector<int> result(n,-1);
        priority_queue<int> Q1;
        priority_queue<pair<int, unsigned>> Q2;
        for(auto x: nums1){
            Q1.push(x);
        }
        for(unsigned i=0; i<n; ++i){
            Q2.push({nums2[i], i});
        }
        while(true){
            while(!Q2.empty() && Q1.top()<=Q2.top().first){Q2.pop();}
            if(Q2.empty()){break;}
            result[Q2.top().second] = Q1.top();
            Q1.pop();
            Q2.pop();
        }
        int loc = 0;
        while(!Q1.empty()){
            while(result[loc]!=-1){++loc;}
            result[loc] = Q1.top();
            Q1.pop();
            ++loc;
        }
        return result;
    }
};

int main(){
    return 0;
}