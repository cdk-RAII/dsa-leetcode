#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(sum_{i=1}^{n} i * (n - i + 1)) ~ O(n^3), where n is nums.size(). For each
// subarray length i (1..n) there are (n - i + 1) starting positions j, and accumulate(...) sums i
// elements, costing O(i) per call. Summing i * (n - i + 1) over all lengths i = 1..n is a classical
// cubic identity (it's the total number of (subarray, element) pairs across every subarray), whose
// leading term is O(n^3) - not the O(n^2) you'd get from counting just the (i, j) pairs themselves,
// since each pair also costs O(i), not O(1).
// Space Complexity: O(1). Only result, sum, and the loop indices are used; accumulate itself uses
// no auxiliary storage beyond its own running total.

// class Solution {
//   public:
//     int subarraySum(vector<int>& nums, int k) {
//         int result = 0;
//         for (size_t i = 1; i <= nums.size(); ++i) {
//             for (size_t j = 0; j < nums.size() - i + 1; ++j) {
//                 int sum = accumulate(nums.begin() + j, nums.begin() + j + i, 0);
//                 if (sum == k) {
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n^2), where n is nums.size(). For each start i, the inner loop accumulates
// nums[j] into a running sum incrementally (O(1) per step) instead of recomputing the subarray sum
// from scratch, so the inner loop over j costs O(n - i). Summing (n - i) for i = 0..n - 1 gives
// O(n^2). This is why it beats Solution 1's O(n^3): the running-sum trick removes the extra O(i)
// per-subarray cost, leaving only the O(n^2) count of (i, j) pairs itself.
// Space Complexity: O(1). Only result and sum are used; no data structure scales with n.

// class Solution {
//   public:
//     int subarraySum(vector<int>& nums, int k) {
//         int result = 0;
//         for (size_t i = 0; i < nums.size(); ++i) {
//             int sum = 0;
//             for (size_t j = i; j < nums.size(); ++j) {
//                 sum = sum + nums[j];
//                 if (sum == k) {
//                     ++result;
//                 }
//             }
//         }
//         return result;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n), where n is nums.size(). A single pass turns nums into its own prefix-sum
// array in place (nums[i] += nums[i - 1]), and for each i we perform O(1) amortized unordered_map
// operations: one lookup for sumsCount[need] and one insert/increment for sumsCount[nums[i]]. No
// nested loop over subarrays is needed because the map lets us look up, in O(1), how many earlier
// prefix sums equal (current prefix sum - k) - each such earlier prefix marks the start of a valid
// subarray ending at i.
// Space Complexity: O(n). sumsCount can grow to hold up to n distinct prefix-sum keys (one per
// index), plus a bounded number of extra zero-initialized entries inserted by sumsCount[need]
// probing values that haven't appeared yet (operator[] default-constructs missing keys) - this does
// not change the asymptotic bound, still O(n). Note: unlike Solutions 1 and 2, this one also
// mutates the caller's nums vector in place, converting it into its own prefix-sum array.

class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
        // Here auto is "int"
        auto result = 0;
        unordered_map<int, int> sumsCount;
        sumsCount.reserve(nums.size());

        // Here auto is "int"
        for (auto i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i == 0) {
                sumsCount[nums[i]]++;
                // Here auto is "int"
                auto need = nums[i] - k;
                if (need == 0) {
                    ++result;
                }
                continue;
            }

            nums[i] = nums[i] + nums[i - 1];
            // Here auto is "int"
            auto need = nums[i] - k;

            if (need == 0) {
                ++result;
            }

            result = result + sumsCount[need];
            sumsCount[nums[i]]++;
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, -1, 3, 0, -2, 4, -3, 1, -1, 2, -2, 5};
    int k = 0;

    // Find the subarray sum
    int result = solution.subarraySum(nums, k);

    // Print the result
    cout << result << "\n";

    return 0;
}