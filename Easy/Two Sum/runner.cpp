#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) return std::vector<int>{i,j};
            }
        }
        return std::vector<int>{};
    }
};

int main() {
    std::vector<int> nums = {-3,4,3,90};
    (new Solution)->twoSum(nums, 0);
    return 0;
}