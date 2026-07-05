#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n + u) ~ O(n), where n is the length of s (equal to t's length after the
// initial size check), and u is the number of distinct characters seen (bounded by the char
// alphabet, a fixed constant - e.g. <= 26 for lowercase English letters, or <= 256 for a general
// 8-bit char). Building the frequency map from s costs O(n), decrementing it from t costs O(n), and
// the final loop over frequency costs O(u), which is O(1) since u is constant. Total: O(n).
// Space Complexity: O(u) ~ O(1). frequency is keyed by char, so its size can never exceed the size
// of the char domain (a fixed constant), regardless of how large n grows - it does not scale with
// n.

class Solution {
  public:
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are different, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> frequency;
        frequency.reserve(s.size());

        // Count the frequency of each character in string s
        // Here auto is "char"
        for (const auto& letter : s) {
            frequency[letter]++;
        }

        // Decrease the frequency based on characters in string t
        // Here auto is "char"
        for (const auto& letter : t) {
            frequency[letter]--;
        }

        // Check if all frequencies are zero, indicating that s and t are anagrams
        // Here auto is "pair<const char, int>"
        for (const auto& [letter, count] : frequency) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "anagram";
    string t = "nagaram";

    // Check if the strings are anagrams
    bool result = solution.isAnagram(s, t);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}