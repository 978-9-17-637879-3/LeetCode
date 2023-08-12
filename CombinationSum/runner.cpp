#include <bits/stdc++.h>

class Solution {
private:
    void generateCombinations(const std::vector<int> &candidates, const int &target,
                              std::vector<std::vector<int>> &permutations, std::vector<int> &path,
                              const int &sum = 0) {
        for (const int &candidate: candidates) {
            int newSum = sum + candidate;
            if (newSum > target) {
                return;
            }

            // ensure that paths are only generated in ascending order, this prevents duplicates without having to store seen paths, suggested by https://github.com/Ryan4253
            if (!path.empty() && candidate < path.back()) {
                continue;
            }

            path.push_back(candidate);

            if (newSum == target) {
                permutations.push_back(path);
                path.pop_back();
                return;
            }

            generateCombinations(candidates, target, permutations, path, newSum);

            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> combinationsVector;
        // ryan also suggested to declare a variable and pass it by reference, which I disregarded when I initially thought of it because it's a tad ugly
        std::vector<int> path;
        generateCombinations(candidates, target, combinationsVector, path);

        return combinationsVector;
    }
};

int main() {
    std::vector<int> candidates = {8, 7, 4, 3};
    (new Solution)->combinationSum(candidates, 11);
}