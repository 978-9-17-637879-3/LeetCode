#include <bits/stdc++.h>

class Solution {
private:
    std::map<std::vector<int>, bool> combinationsSeenMap;

    void orderRespectiveInsert(std::vector<int> &v, int newElem) {
        if (v.empty()) {
            v.push_back(newElem);
            return;
        }

        int insertionIndex = v.size();
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= newElem) {
                insertionIndex = i;
                break;
            }
        }

        v.insert(v.begin() + insertionIndex, newElem);
    }

    void generateCombinations(const std::vector<int> &candidates, const int &target,
                              std::vector<std::vector<int>> &permutations, const std::vector<int> &path = {},
                              const int &sum = 0) {
        for (const int &candidate: candidates) {
            int newSum = sum + candidate;
            if (newSum > target) {
                return;
            }

            std::vector<int> newPath = path;
            orderRespectiveInsert(newPath, candidate);

            if (combinationsSeenMap.count(newPath) == 1) {
                continue;
            }
            combinationsSeenMap[newPath] = true;

            if (newSum == target) {
                permutations.push_back(newPath);
                return;
            }

            generateCombinations(candidates, target, permutations, newPath, newSum);
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end(), [](const int &a, const int &b) -> bool {
            return a < b;
        });

        std::vector<std::vector<int>> combinationsVector;
        generateCombinations(candidates, target, combinationsVector);

        return combinationsVector;
    }
};

int main() {
    std::vector<int> candidates = {8, 7, 4, 3};
    (new Solution)->combinationSum(candidates, 11);
}