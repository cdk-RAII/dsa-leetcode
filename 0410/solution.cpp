#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n log(sumMax - sumMin + 1)) ~ O(n log(sumMax - sumMin + 1)),
// where n is the size of nums.
//
// The first for loop scans all n elements once. For each element it:
// 1. Updates sumMin = max(nums), which costs O(1).
// 2. Adds the element to sumMax, which costs O(1).
// Therefore, this preprocessing phase costs O(n).
//
// The binary search then works on the integer capacity range
// [sumMin, sumMax]. The number of possible values in this range is
// sumMax - sumMin + 1, so the binary search requires
// O(log(sumMax - sumMin + 1)) iterations.
//
// During every binary-search iteration, the second for loop scans all n
// elements. For each element it performs only O(1) work: checking whether
// the current subarray would exceed mid, possibly starting a new subarray,
// and adding the current value to tempT. Therefore, one feasibility check
// costs O(n).
//
// Combining all phases:
// O(n + n log(sumMax - sumMin + 1))
// ~ O(n log(sumMax - sumMin + 1)).
//
// Space Complexity: O(1).
//
// The algorithm uses only a constant number of scalar variables such as
// numsS, sumMin, sumMax, searchS, mid, testK, and tempT.
// No additional data structure grows with n, so the auxiliary space is O(1).

class Solution {
  public:
    int splitArray(vector<int>& nums, int k) {
        int numsS = static_cast<int>(nums.size());
        int sumMin = 0;
        int sumMax = 0;

        for (const int& num : nums) {
            sumMin = max(sumMin, num);
            sumMax += num;
        }

        while (sumMax > sumMin) {
            int searchS = sumMax - sumMin;
            int mid = sumMin + searchS / 2;
            int testK = 1;
            int tempT = 0;

            for (const int& num : nums) {
                if (tempT + num > mid) {
                    ++testK;
                    tempT = 0;
                }

                tempT += num;
            }

            if (testK <= k) {
                sumMax = mid;
            } else {
                sumMin = mid + 1;
            }
        }

        return sumMin;
    }
};

// Complexity Analysis:
// Time Complexity: O(n + n log(U - sumMin + 1))
//                  ~ O(n log(U - sumMin + 1)),
// where:
//   n = nums.size()
//   sumMin = max(nums)
//   U = the initial optimized upper bound, equal to the maximum sum of
//       any contiguous subarray of length (n - k + 1).
//
// The first for loop performs a sliding-window computation.
//
// maxChunkS = n - k + 1 is the maximum possible length of any one subarray
// in a valid partition into k non-empty subarrays.
//
// The loop maintains the sum of the current window of length at most
// maxChunkS. Each element is added to tempT once and, once the window
// exceeds maxChunkS, an element is removed once. Therefore, all window
// updates together cost O(n).
//
// At the same time, the loop computes sumMin = max(nums), also in O(n).
//
// Thus, the complete preprocessing phase costs O(n).
//
// Unlike the standard solution, the initial upper bound is not the total
// sum of the entire array. Instead, sumMax is initialized to the maximum
// sum of any window of length maxChunkS = n - k + 1.
//
// Since nums[i] >= 0, this is a valid upper bound for the largest subarray
// sum in an optimal k-way partition. Therefore, if U denotes this initial
// optimized upper bound, the binary-search range contains
// U - sumMin + 1 possible capacity values.
//
// The binary search therefore requires
// O(log(U - sumMin + 1))
// iterations in the worst case.
//
// Each binary-search iteration performs a complete scan of nums, costing
// O(n). During this scan, the code performs O(1) work per element.
// Additionally, when a subarray is completed, tempTMax is updated in O(1).
//
// Therefore, the binary-search phase costs
// O(n log(U - sumMin + 1)).
//
// There is also a second optimization:
// when testK == k, tempTMax stores the largest sum among the exactly k
// subarrays produced by the current feasibility scan. That partition is
// valid, so tempTMax is a feasible upper bound and the code tightens the
// search range using:
//
//     sumMax = min(tempTMax, sumMax);
//
// This can reduce the remaining search range and therefore reduce the
// number of later O(n) scans in practice. However, it does not change the
// worst-case asymptotic logarithmic bound, so the worst-case complexity
// remains:
//
// O(n + n log(U - sumMin + 1)) ~ O(n log(U - sumMin + 1)).
//
// Space Complexity: O(1).
//
// The algorithm uses only scalar variables:
// numsS, leftPtr, sumMin, sumMax, tempT, maxChunkS, i, searchS, mid,
// testK, and tempTMax.
//
// No auxiliary vector, array, map, set, recursion stack, or other
// input-dependent structure is allocated, so auxiliary space is O(1).

class Solution {
  public:
    int splitArray(vector<int>& nums, int k) {
        int numsS = static_cast<int>(nums.size());
        int leftPtr = 0;
        int sumMin = 0;
        int sumMax = 0;
        int tempT = 0;
        int maxChunkS = numsS - k + 1;

        for (int i = 0; i < numsS; ++i) {
            sumMin = max(nums[i], sumMin);
            tempT += nums[i];

            if (i >= maxChunkS) {
                tempT -= nums[leftPtr];
                leftPtr++;
            }

            sumMax = max(tempT, sumMax);
        }
        while (sumMax > sumMin) {
            int searchS = sumMax - sumMin;
            int mid = sumMin + searchS / 2;
            int testK = 1;
            tempT = 0;
            int tempTMax = 0;

            for (const int& num : nums) {
                if (tempT + num > mid) {
                    tempTMax = max(tempT, tempTMax);
                    testK++;
                    tempT = 0;
                }

                tempT += num;
            }

            tempTMax = max(tempT, tempTMax);

            if (testK < k) {
                sumMax = mid;
            } else if (testK > k) {
                sumMin = mid + 1;
            } else {
                // For testK == k
                sumMax = min(tempTMax, sumMax);
            }
        }

        return sumMax;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {10, 1, 0, 0};
    int k = 5;

    // Find the target
    int result = solution.splitArray(nums, k);

    // Print the result
    cout << result << "\n";

    return 0;
}