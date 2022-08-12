#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        if (s.empty()){
            return {0};
        }
        std::vector<std::pair<int, int>> arr;
        for (int i=0; i<26; ++i){
            arr.push_back({-1, -1});
        }
        for (int i=0; i<int(s.length()); ++i){
            auto ch = size_t(s[i]-'a');
            if(arr[ch].first==-1){
                arr[ch].first = i;
            }
            if(i > arr[ch].second){
                arr[ch].second = i;
            }
        }

        std::sort(arr.begin(), arr.end(),\
            [](std::pair<int, int> a, std::pair<int, int> b){
                return a.first < b.first;
            }
        );
        std::vector<int> result;
        auto iter = arr.cbegin();
        while (iter!=arr.cend() && iter->first==-1) {++iter;}
        int prev_bar = 0;
        int x = iter->second;
        for (++iter; iter!=arr.cend(); ++iter){
            if(iter->first > x){
                result.push_back(iter->first - prev_bar);
                prev_bar = iter->first;
            }
            if(iter->second > x){x = iter->second;}
        }
        result.push_back(int(s.length()) - prev_bar);
        return result;
    }
};

int main(){
    Solution sol;
    while(true){
        std::string s;
        std::cin >> s;
        if(s=="exit"){break;}
        auto result = sol.partitionLabels(s);
        for (auto val : result){
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    return 0;
}