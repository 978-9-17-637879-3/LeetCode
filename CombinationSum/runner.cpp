#include <bits/stdc++.h>

class Solution {
private:
    void generateCombinations(const std::vector<int> &candidates, const int &target, std::set<std::vector<int>> &permutations, std::vector<int> path = {}, const int &sum = 0) {
        for (const int &candidate : candidates) {
            int newSum = sum + candidate;
            if (newSum > target) {
                return;
            }

            path.push_back(candidate);
            if (newSum == target) {
                std::sort(path.begin(), path.end(), [](const int &a, const int &b) -> bool {
                    return a < b;
                });
                permutations.insert(path);
                return;
            }

            generateCombinations(candidates, target, permutations, path, newSum);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end(), [](const int &a, const int &b) -> bool {
            return a < b;
        });

        std::set<std::vector<int>> combinationsSet;
        generateCombinations(candidates, target, combinationsSet);

        std::vector<std::vector<int>> combinationsVector (combinationsSet.begin(), combinationsSet.end());
        return combinationsVector;
    }
};

int main() {
    std::vector<int> candidates = {8,7,4,3};
    (new Solution)->combinationSum(candidates, 11);
}