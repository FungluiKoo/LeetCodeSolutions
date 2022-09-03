#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int,unordered_set<int>> neighborsof;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(auto &edge : edges){
            neighborsof[edge[0]].insert(edge[1]);
            neighborsof[edge[1]].insert(edge[0]);
        }
        queue<int> Q;
        for(int v=0; v<n; ++v){
            if(neighborsof[v].size()==1){
                Q.push(v);
            }
        }
        int v_cnt = n;
        while(v_cnt>2){
            int s = Q.size();
            for(int i=0; i<s; ++i){
                auto v = Q.front();
                Q.pop();
                for(const auto u: neighborsof[v]){ // actually only 1 neighbor
                    neighborsof[u].erase(v);
                    if(neighborsof[u].size()==1){Q.push(u);}
                }
                neighborsof.erase(v);
            }
            v_cnt -= s;
        }
        vector<int> result;
        for(auto it=neighborsof.begin(); it!=neighborsof.end(); ++it){
            result.push_back(it->first);
        }
        return result;
    }
};

int main(){
    Solution sol;
    return 0;
}