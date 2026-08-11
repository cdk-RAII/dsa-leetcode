#include <iostream>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(log(x/2)) ~ O(log x), where x is the input integer. If x >= 2, the binary
// search initially considers the range [1, x / 2]. In every iteration of the while loop, the search
// range is reduced approximately by half. Each iteration performs only O(1) work, including
// calculating the midpoint, comparing midpoint with x / midpoint, and updating the search
// boundaries. Therefore, the binary search requires O(log(x / 2)) iterations, which simplifies to
// O(log x) time. For x < 2, the function returns immediately in O(1) time.
// Space Complexity: O(1), where x is the input integer. The algorithm uses only a constant amount
// of extra space for the variables start, end, test, searchSize, and midpoint. No additional data
// structures or recursion are used.

class Solution {
  public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int start = 1;
        int end = x / 2;
        int test = 0;

        while (end >= start) {
            int searchSize = end - start;
            int midpoint = start + searchSize / 2;

            // To avoid overflow, we compare midpoint <= x / midpoint instead of midpoint * midpoint
            // <= x.
            if (midpoint <= x / midpoint) {
                test = midpoint;
                start = midpoint + 1;
            } else {
                end = midpoint - 1;
            }
        }

        return test;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    int x = 16;

    // Find the square root
    int result = solution.mySqrt(x);

    // Print the result
    cout << result << "\n";

    return 0;
}