#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(1) best case, O(log n) worst case, where n is the size of the input vector
// nums. The initial check nums[start] <= nums[end] takes O(1) time and immediately returns the
// minimum when the array is already sorted. Otherwise, the binary-search loop repeatedly reduces
// the search range approximately by half, requiring O(log n) iterations, with O(1) work per
// iteration. Therefore, the overall time complexity is O(log n) in the worst case, with an
// improved O(1) best case due to the initial sorted-array check.
// Space Complexity: O(1), where n is the size of the input vector nums. The algorithm uses only a
// constant amount of extra space for variables numsS, start, end, searchS, and mid. No additional
// data structures or recursion are used.

class Solution {
  public:
    int findMin(vector<int>& nums) {
        int numsS = static_cast<int>(nums.size());
        int start = 0;
        int end = numsS - 1;

        if (nums[start] <= nums[end]) {
            return nums[start];
        }

        while (end > start) {
            int searchS = end - start;
            int mid = start + searchS / 2;

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return nums[start];
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Find the minimum in the rotated sorted array
    int result = solution.findMin(nums);

    // Print the result
    cout << result << "\n";

    return 0;
}