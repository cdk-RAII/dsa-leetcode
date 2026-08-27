#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Complexity Analysis:
//
// Time Complexity: O(n) expected.
//
// Let n = s.size().
//
// charIdx.reserve(sS) performs a one-time allocation/rehashing operation
// to provide capacity for approximately n elements. This is O(n) in the
// amount of storage being prepared.
//
// The main loop then processes each of the n characters exactly once.
//
// For each character:
// 1. charIdx.find(s[i]) is expected O(1).
// 2. If found, charIdx[s[i]] is expected O(1).
// 3. max() and the arithmetic operations are O(1).
// 4. charIdx[s[i]] = i is expected O(1).
//
// Therefore, the total expected time is:
//
// O(n + n) ~ O(n).
//
// Because unordered_map operations can theoretically degrade to O(n)
// under pathological hash collisions, the theoretical worst-case time is
// O(n^2).
//
// Space Complexity: O(n).
//
// The implementation explicitly calls charIdx.reserve(sS), causing the
// unordered_map to allocate bucket storage proportional to n.
//
// Although the problem's character domain is bounded and the number of
// distinct char keys is therefore O(1), the actual auxiliary memory
// allocated by this implementation can be O(n) because of reserve(sS).
//
// Therefore, for the exact implementation:
// Auxiliary Space: O(n).

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int sS = static_cast<int>(s.size());
        unordered_map<char, int> charIdx;
        charIdx.reserve(sS);
        int stringStart = 0;
        int longestSubstring = 0;
        for (int i = 0; i < sS; ++i) {
            auto it = charIdx.find(s[i]);
            if (it != charIdx.end()) {
                stringStart = max(charIdx[s[i]] + 1, stringStart);
            }
            int tempL = i - stringStart + 1;
            longestSubstring = max(tempL, longestSubstring);
            charIdx[s[i]] = i;
        }
        return longestSubstring;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "ccbbcc";

    // Calculate the length of the longest substring without repeating characters
    int result = solution.lengthOfLongestSubstring(s);

    // Print the result
    cout << result << "\n";

    return 0;
}