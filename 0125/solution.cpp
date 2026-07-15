#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n + n/2) ~ O(n), where n is the length of the input string. erase_if()
// scans the entire string once and removes all non-alphanumeric characters in O(n). Then
// ranges::transform() traverses the filtered string once to convert every character to lowercase
// (O(n)). Finally, the two-pointer loop compares one pair of characters per iteration, executing
// at most n/2 iterations (O(n/2)). Summing all three passes gives O(n + n + n/2), which
// simplifies to O(n).
// Space Complexity: O(1), where n is the length of the input string. Both erase_if() and
// ranges::transform() modify the original string in place, and the palindrome check uses only two
// integer indices regardless of the input size.

// class Solution {
//   public:
//     bool isPalindrome(string s) {
//         erase_if(s, [](unsigned char c) {
//             return !isalnum(c);
//         });

//         ranges::transform(s, s.begin(), [](unsigned char c) {
//             return static_cast<unsigned char>(tolower(c));
//         });

//         int i = 0;
//         int j = static_cast<int>(s.size()) - 1;

//         while (i < j) {
//             if (s[i] != s[j]) {
//                 return false;
//             }

//             i++;
//             j--;
//         }

//         return true;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n), where n is the length of the input string. The two pointers move toward
// the center of the string. Although there are two inner while loops to skip non-alphanumeric
// characters, each character is skipped or compared at most once by either pointer. Since neither
// pointer ever moves backward, the total number of pointer movements across the entire algorithm
// is at most n, giving an overall time complexity of O(n).
// Space Complexity: O(1), where n is the length of the input string. Only two integer indices and
// two temporary unsigned char variables are used regardless of the input size.

class Solution {
  public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;

        while (i < j) {
            while (i < j && !isalnum(static_cast<unsigned char>(s[i]))) {
                i++;
            }

            while (i < j && !isalnum(static_cast<unsigned char>(s[j]))) {
                j--;
            }

            unsigned char leftlower =
                static_cast<unsigned char>(tolower(static_cast<unsigned char>(s[i])));
            unsigned char rightlower =
                static_cast<unsigned char>(tolower(static_cast<unsigned char>(s[j])));

            if (leftlower != rightlower) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "A man, a plan, a canal: Panama";

    // Check if the string is a palindrome
    bool result = solution.isPalindrome(s);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}