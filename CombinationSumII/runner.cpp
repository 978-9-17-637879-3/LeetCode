#include <bits/stdc++.h>

class Solution {
private:
    std::vector<std::vector<int>> seenCombinations;
    void generateCombinations(const std::vector<int> &candidates, const int &target,
                              std::vector<std::vector<int>> &combinations, std::vector<int> &path, std::vector<int> &usedIndices,
                              const int &sum = 0) {
        for (int i = usedIndices.empty() ? 0 : usedIndices.back() + 1; i < candidates.size(); i++) {
//            if (std::binary_search(usedIndices.begin(), usedIndices.end(), i)) {
//                continue;
//            }
            int newSum = sum + candidates[i];
            if (newSum > target) {
                return;
            }

            // ensure that paths are only generated in ascending order, this prevents duplicates without having to store seen paths, suggested by https://github.com/Ryan4253
            if (!path.empty() && candidates[i] < path.back()) {
                continue;
            }

            path.push_back(candidates[i]);
            if (std::find(seenCombinations.begin(), seenCombinations.end(),path) != seenCombinations.end()) {
                path.pop_back();
                continue;
            }
            seenCombinations.push_back(path);
            usedIndices.push_back(i);

            if (newSum == target) {
                combinations.push_back(path);
                path.pop_back();
                usedIndices.pop_back();
                return;
            }

            generateCombinations(candidates, target, combinations, path, usedIndices, newSum);

            path.pop_back();
            usedIndices.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> combinations;
        // ryan also suggested to declare a variable and pass it by reference, which I disregarded when I initially thought of it because it's a tad ugly
        std::vector<int> path;
        std::vector<int> usedIndices;
        generateCombinations(candidates, target, combinations, path, usedIndices);

        return combinations;
    }
};

int main() {
    std::vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    (new Solution)->combinationSum2(candidates, 30);
}