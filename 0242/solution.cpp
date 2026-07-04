#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the length of the input strings s and t. We iterate through
// both strings once to build the frequency map and then iterate through the map to check for any
// non-zero counts. Space Complexity: O(n), where n is the length of the input strings s and t. We
// create an unordered_map to store the frequency of characters in string s.
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