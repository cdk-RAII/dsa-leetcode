#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n) worst case, O(log n) when the duplicate values do not prevent us from
// identifying the sorted half. In the usual case, the algorithm behaves like binary search because
// each iteration can discard approximately half of the current search range, giving O(log n) time.
// However, when nums[start] == nums[mid] and/or nums[end] == nums[mid], the duplicate values can
// make it impossible to determine which half is sorted. In that situation, the algorithm falls
// back to shrinking the search range by only one position from the left and/or right. Therefore,
// in the worst case, such as an array containing many identical values, the search range can be
// reduced by only O(1) elements per iteration, resulting in O(n) total time.
// More precisely, the binary-search work contributes O(log n) when the sorted half can be
// determined, while repeated duplicate-boundary reductions can contribute O(n). Therefore:
// Time Complexity: O(log n + n) ~ O(n) worst case.
// Space Complexity: O(1), where n is the size of the input vector nums. The algorithm uses only a
// constant amount of extra space for the variables numsS, start, end, searchS, and mid. No
// additional data structures or recursion are used.

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
        int numsS = static_cast<int>(nums.size());
        int start = 0;
        int end = numsS - 1;

        while (end >= start) {
            int searchS = end - start;
            int mid = start + searchS / 2;

            if (nums[mid] == target) {
                return true;
            }
            if (nums[start] == nums[mid]) {
                start++;
            }
            if (nums[end] == nums[mid]) {
                end--;
            } else if (nums[start] <= nums[mid]) {
                if (nums[mid] > target && nums[start] <= target) {
                    if (nums[start] == target) {
                        return true;
                    }

                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && nums[end] >= target) {
                    if (nums[end] == target) {
                        return true;
                    }

                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    // Find the target
    bool result = solution.search(nums, target);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}