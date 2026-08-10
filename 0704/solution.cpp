#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(log n), where n is the size of the input vector nums. In every iteration of
// the while loop, the search range is reduced approximately by half. If the current search range
// contains n elements, after one iteration it contains approximately n / 2 elements, then n / 4,
// n / 8, and so on. The loop therefore performs at most O(log n) iterations, and each iteration
// performs only O(1) work for calculating the midpoint, comparing values, and updating the search
// boundaries. Therefore, the total time complexity is O(log n).
// Space Complexity: O(1), where n is the size of the input vector nums. The algorithm uses only a
// constant amount of extra space for the variables start, end, searchSize, and midpoint. No
// additional data structures whose size depends on n are allocated.

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;

        while (end >= start) {
            int searchSize = end - start + 1;
            int midpoint = start + searchSize / 2;

            if (nums[midpoint] == target) {
                return midpoint;
            } else if (nums[midpoint] < target) {
                start = midpoint + 1;
            } else {
                end = midpoint - 1;
            }
        }

        return -1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    // Find the target
    int result = solution.search(nums, target);

    // Print the result
    cout << result << "\n";

    return 0;
}