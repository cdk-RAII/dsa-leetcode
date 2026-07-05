#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(S_cmp + L) ~ O(S), where S is the sum of the lengths of all strings in strs,
// and L is the length of strs[0] (the initial prefixStr). The inner while loop's comparisons in
// iteration i are bounded by strs[i].size() (loop condition j < strs[i].size()), so summed across
// all n - 1 iterations they total at most S. The erase(j) calls only ever shrink prefixStr, never
// grow it, so their combined cost telescopes to at most L (the initial prefixStr length), which is
// itself <= S. Adding both terms and simplifying gives O(S).
// Space Complexity: O(1). We only use a constant number of extra index variables (i, j); prefixStr
// is built in-place from strs[0] via erase, with no additional buffer proportional to the input.

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
// Time Complexity: O(L * maxLen) ~ O(L * maxLen), where L is the length of strs[0] (the initial
// prefixStr), and maxLen is the length of the longest string in strs. prefixStr only ever shrinks
// (pop_back), never grows, across the whole run, so the total number of failed find()/pop_back
// attempts telescopes to at most L (same argument as the primary solution above). Each find() call
// is a substring search costing O(strs[i].size() * prefixStr.size()) in the worst case (naive
// search), and both factors are bounded by maxLen and L respectively, giving a worst-case total of
// O(L * maxLen). This is strictly worse than the O(S) bound of the primary erase()-based solution
// above, since L * maxLen can exceed S when strings are long and repeatedly near-match.
// Space Complexity: O(1). pop_back() mutates prefixStr in place; no extra buffer proportional to
// the input is allocated.

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