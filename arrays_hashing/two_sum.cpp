// Source: https://leetcode.com/problems/two-sum/
// Author: Ngoc-Tien To

// Instead of using two nested loops to check all pairs,
// we can use a hash map to check if the complement exists.
// This reduces the time complexity from O(n^2) to O(n).


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unMap;
        for(int i = 0; i < nums.size(); i++){
            if(unMap.find(target - nums[i]) != unMap.end()){
                return {i, unMap[target - nums[i]]};
            }
            unMap[nums[i]] = i;
        }
        return {};
    }
};