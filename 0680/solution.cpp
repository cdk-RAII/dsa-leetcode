#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n/2 + n + n) ~ O(n), where n is the length of the input string. The initial
// two-pointer scan compares one pair of characters per iteration, executing at most n/2
// iterations (O(n/2)). Upon encountering the first mismatch, the algorithm checks the two
// possible deletions by calling isPalindrome(s, left, right - 1) and isPalindrome(s, left + 1,
// right). In the worst case, the first call returns false only after scanning the remaining
// substring, forcing the second call to execute as well, and it may also scan the remaining
// substring. Summing all three steps gives O(n/2 + n + n), which simplifies to O(n).
// Space Complexity: O(1), where n is the length of the input string. The algorithm uses only a
// few integer indices (left and right), and isPalindrome() receives the string by const
// reference, so no additional data structures proportional to the input size are allocated.

class Solution {
  public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "abca";

    // Check if the string is a palindrome
    bool result = solution.validPalindrome(s);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}