#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        int stringLen = s.size();
        int longestLength = 0;
        for (int i = 0; i < stringLen - longestLength; i++) {
            int length = 1;
            std::vector<char> existing = {s[i]};

            for (int j = i+1; j < stringLen; j++) {
                if (std::find(existing.begin(), existing.end(), s[j]) != existing.end())
                    break;

                existing.push_back(s[j]);
                length++;
            }

            if (length > longestLength) {
                longestLength = length;
            }
        }

        return longestLength;
    }
};

int main() {
    std::string s = "";
    std::cout << (new Solution)->lengthOfLongestSubstring(s) << std::endl;
}