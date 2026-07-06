#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is the size of nums. The outer loop of the first pass
// runs n times. The inner while loop performs swaps, but each swap places some value v into its
// correct home index v - 1 (nums[v - 1] == v) permanently: once a slot holds its correct value, any
// future visit to it fails the nums[i] != nums[nums[i] - 1] check immediately, so it is never
// swapped again, and duplicate values are similarly blocked from re-triggering a swap on an
// already-correct slot. Since each swap permanently fixes one previously-unfixed slot, the total
// number of swaps across the entire first pass is bounded by n, making it O(n) amortized rather
// than O(n^2). The second loop is a single O(n) pass to find the first index where nums[i] != i
// + 1. Total: O(n). Space Complexity: O(1). The algorithm swaps elements in place within nums and
// only uses a constant number of extra variables (numsSize, i); no additional data structures scale
// with the input size.

class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
        int numsSize = static_cast<int>(nums.size());

        // Here auto is "int"
        for (auto i = 0; i < numsSize; ++i) {
            while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Here auto is "int"
        for (auto i = 0; i < numsSize; ++i) {
            // We compare nums[i] != i + 1 (not i != nums[i] - 1) because nums[i] can be INT_MIN
            // here (the first loop's nums[i] > 0 guard leaves such values untouched). Computing
            // nums[i] - 1 would then evaluate INT_MIN - 1, which underflows past INT_MIN - signed
            // integer overflow, which is undefined behavior in C++, not just a missed range check.
            // i + 1 is always safe since i is bounded by numsSize.
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return numsSize + 1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {3, 4, -1, 1};

    // Find the first missing positive
    int result = solution.firstMissingPositive(nums);

    // Print the result
    cout << result << "\n";

    return 0;
}