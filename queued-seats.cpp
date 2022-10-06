#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> seatsAssigned(vector<int> &arr){
        int n = arr.size();
        vector<int> result(n);
        unordered_set<int> seats;
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            q.push({i,arr[i]});
        }
        while(!q.empty()){
            auto [person, seat] = q.front();
            q.pop();
            if(seats.count(seat)==0){
                seats.insert(seat);
                result[person] = seat;
            }else{
                q.push({person, seat+1});
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,3,2,4};
    auto result = sol.seatsAssigned(arr);
    for(auto x:result){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}