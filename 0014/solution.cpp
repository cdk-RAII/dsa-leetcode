#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(S), where S is the sum of all characters in all strings. In the worst case, we
// have to compare all characters of all strings. Space Complexity: O(1), as we are only using a
// constant amount of extra space.
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefixStr = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            size_t j = 0;
            while (j < prefixStr.size() && j < strs[i].size() && prefixStr[j] == strs[i][j]) {
                ++j;
            }
            prefixStr.erase(j);
            if (prefixStr.empty()) {
                break;
            }
        }
        return prefixStr;
    }
};

// Complexity Analysis:
// Time Complexity: O(S), where S is the sum of all characters in all strings. In the worst case, we
// have to compare all characters of all strings. Space Complexity: O(1), as we are only using a
// constant amount of extra space.
// class Solution {
//   public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string prefixStr = strs[0];
//         for (size_t i = 1; i < strs.size(); ++i) {
//             while (strs[i].find(prefixStr) != 0) {
//                 prefixStr.pop_back();
//                 if (prefixStr.empty()) {
//                     return "";
//                 }
//             }
//         }
//         return prefixStr;
//     }
// };

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<string> strs = {"flower", "flow", "flight"};

    // Find longest common prefix
    string lcp = solution.longestCommonPrefix(strs);

    // Print the result
    cout << lcp << "\n";

    return 0;
}