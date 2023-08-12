#include <bits/stdc++.h>

class Solution {
private:
    std::unordered_map<int, std::vector<int>> depthMap;
    void generateCombinations(const std::vector<int> &candidates, const int &target,
                              std::vector<std::vector<int>> &combinations, std::vector<int> &path, std::vector<int> &usedIndices, int depth = 0,
                              const int &sum = 0) {
        for (int i = usedIndices.empty() ? 0 : usedIndices.back() + 1; i < candidates.size(); i++) {
            int newSum = sum + candidates[i];
            if (newSum > target) {
                depthMap.erase(depth);
                return; // backtrack
            }

            // ensure that paths are only generated in ascending order, this prevents duplicates without having to store seen paths, suggested by https://github.com/Ryan4253
            if (!path.empty() && candidates[i] < path.back()) {
                continue; // goto next node under this parent
            }

            path.push_back(candidates[i]);
            if (depthMap.find(depth) != depthMap.end()) {
                if (std::binary_search(depthMap[depth].begin(), depthMap[depth].end(), candidates[i])) {
                    path.pop_back();
                    continue; // goto next node under this parent
                }
                depthMap[depth].push_back(candidates[i]);
            } else {
                depthMap[depth] = std::vector<int>{candidates[i]};
            }
            usedIndices.push_back(i);

            if (newSum == target) {
                combinations.push_back(path);
                path.pop_back(); // reset path for further use
                usedIndices.pop_back(); // this candidate can still be used on other paths
                depthMap.erase(depth);
                return; // backtrack since there can be no other non-duplicate solutions on this path(any other unique solution would be greater than target)
            }

            generateCombinations(candidates, target, combinations, path, usedIndices, depth+1, newSum);

            path.pop_back();
            usedIndices.pop_back();
        }

        depthMap.erase(depth);
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
    std::vector<int> candidates = {3,1,3,5,1,1};
    (new Solution)->combinationSum2(candidates, 8);
}