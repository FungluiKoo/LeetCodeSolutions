#include <algorithm>
#include <forward_list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),\
            [](vector<int> &a, vector<int> &b){
                return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
            }
        );
        forward_list<vector<int>> ls;
        for (auto person : people){
            ls.insert_after(next(ls.before_begin(),person[1]), person);
        }
        vector<vector<int>> result(ls.begin(), ls.end());
        return result;
    }
};