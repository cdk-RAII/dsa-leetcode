#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n/2) ~ O(n), where n is the length of the input string. std::reverse()
// swaps the first and last characters, then the second and second-last, and so on, performing
// n/2 swaps in total. Since constant factors are ignored in Big-O notation, O(n/2) simplifies
// to O(n).
// Space Complexity: O(1), where n is the length of the input string. std::reverse() reverses the
// string in place using only a constant amount of extra storage.

// class Solution {
//   public:
//     void reverseString(vector<char>& s) { reverse(s.begin(), s.end()); }
// };

// Complexity Analysis:
// Time Complexity: O(n/2) ~ O(n), where n is the length of the input string. The two pointers
// move toward the center, swapping one pair of characters in each iteration. The loop executes
// n/2 times, so the total time complexity is O(n/2), which simplifies to O(n).
// Space Complexity: O(1), where n is the length of the input string. Only two integer indices are
// used regardless of the input size.

class Solution {
  public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

// Complexity Analysis:
// Time Complexity: O(n/2) ~ O(n), where n is the length of the input string. The two pointers
// move toward the center, and each iteration swaps one pair of characters using a temporary
// variable. The loop executes n/2 times, giving O(n/2), which simplifies to O(n).
// Space Complexity: O(1), where n is the length of the input string. Only two integer indices and
// one temporary character variable are used, all requiring constant extra space.

// class Solution {
//   public:
//     void reverseString(vector<char>& s) {
//         int i = 0;
//         int j = static_cast<int>(s.size()) - 1;

//         while (i < j) {
//             char temp = s[i];
//             s[i] = s[j];
//             s[j] = temp;

//             i++;
//             j--;
//         }
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n/2) ~ O(n), where n is the length of the input string. The two pointers
// move toward the center, performing one XOR-based swap per iteration. The loop executes n/2
// times, so the total time complexity is O(n/2), which simplifies to O(n).
// Space Complexity: O(1), where n is the length of the input string. The algorithm swaps the
// characters using XOR operations without allocating any additional variables or data structures.

// class Solution {
//   public:
//     void reverseString(vector<char>& s) {
//         int i = 0;
//         int j = static_cast<int>(s.size()) - 1;

//         while (i < j) {
//             s[i] ^= s[j];
//             s[j] ^= s[i];
//             s[i] ^= s[j];

//             i++;
//             j--;
//         }
//     }
// };

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Reverse the string
    solution.reverseString(s);

    // Print the result
    for (char c : s) {
        cout << c;
    }
    cout << "\n";

    return 0;
}