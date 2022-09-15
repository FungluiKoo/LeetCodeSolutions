#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> spectrum;
        for(int i=0; i<nums.size(); i++){
            spectrum[nums[i]].push_back(i);
        }
        for(auto iter = spectrum.begin(); iter!=spectrum.end(); iter++){
            int complement = target - (iter->first);
            auto search = spectrum.find(complement);
            if(search!=spectrum.end()){
                return {iter->second.front(), search->second.back()};
            }
        }
        return {0};
    }
};