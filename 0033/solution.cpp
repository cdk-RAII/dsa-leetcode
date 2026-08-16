#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(log n), where n is the size of the input vector nums. The algorithm performs
// a modified binary search. In every iteration, it determines which half of the current search
// range is sorted and then discards the other half. Therefore, the search range is reduced
// approximately by half in every iteration, resulting in O(log n) iterations. Each iteration
// performs only O(1) work for calculating the midpoint, checking which half is sorted, and
// determining whether target lies within that half. Therefore, the total time complexity is
// O(log n).
// Space Complexity: O(1), where n is the size of the input vector nums. The algorithm uses only a
// constant amount of extra space for the variables numsS, start, end, searchS, and mid. No
// additional data structures or recursion are used.

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int numsS = static_cast<int>(nums.size());
        int start = 0;
        int end = numsS - 1;

        while (end >= start) {
            int searchS = end - start;
            int mid = start + searchS / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[start] <= nums[mid]) {
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
    int target = 8;

    // Find the target
    int result = solution.search(nums, target);

    // Print the result
    cout << result << "\n";

    return 0;
}