#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto ticket: tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        stack<string> S;
        S.push("JFK");
        while(!S.empty()){
            auto curr = S.top();
            if(adj[curr].empty()){
                result.push_back(curr);
                S.pop();
            }else{
                S.push(adj[curr].top());
                adj[curr].pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};