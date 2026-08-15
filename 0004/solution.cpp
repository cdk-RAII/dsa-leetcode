#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(log(nums2S + 1)) ~ O(log n), where nums2S is the size of nums2 and n is the
// size of the larger input array nums1. Unlike the standard binary-search solution that searches
// across all possible partition positions of the larger array, this implementation restricts the
// search to the only partition positions that are mathematically possible:
//     midL1Min <= midL1 <= midL1Max
// where the search range contains at most nums2S + 1 possible partition positions. Therefore,
// the binary search requires O(log(nums2S + 1)) iterations instead of O(log(nums1S + 1))
// iterations. Since nums2S <= nums1S, this reduces the number of possible partition positions when
// the two input arrays have significantly different sizes, while retaining the same O(log(min(m,
// n))) asymptotic bound when expressed in terms of the smaller array.
// Space Complexity: O(1), where n is the combined size of nums1 and nums2. The algorithm uses only
// a constant amount of extra space for integer, boolean, and double variables. Swapping nums1 and
// nums2 swaps the vector objects themselves and does not create a new array. No additional data
// structures whose size depends on n are allocated.

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            swap(nums1, nums2);
        }

        int nums1S = static_cast<int>(nums1.size());
        int nums2S = static_cast<int>(nums2.size());
        int totalE = nums1S + nums2S;
        int midL1Max = ((totalE + 1) / 2) - 1;
        int midL1Min = midL1Max - nums2S;
        double median = 0;

        while (midL1Max >= midL1Min) {
            int searchSize = midL1Max - midL1Min;
            int midL1 = midL1Min + searchSize / 2;
            int midR1 = midL1 + 1;
            int nums1LE = midL1 + 1;
            int midL2 = ((totalE - 1) / 2) - nums1LE;
            int midR2 = midL2 + 1;

            // Condition nums1 midLeft <= nums2 midRight
            bool condition1 = midL1 >= 0 && midR2 < nums2S ? nums1[midL1] <= nums2[midR2] : true;
            // Condition nums2 midLeft <= nums1 midRight
            bool condition2 = midL2 >= 0 && midR1 < nums1S ? nums2[midL2] <= nums1[midR1] : true;

            if (condition1 && condition2) {
                int midLMax =
                    max(midL1 < 0 ? INT_MIN : nums1[midL1], midL2 < 0 ? INT_MIN : nums2[midL2]);
                int midRMin = min(midR1 >= nums1S ? INT_MAX : nums1[midR1],
                                  midR2 >= nums2S ? INT_MAX : nums2[midR2]);
                median = totalE % 2 ? midLMax : (midLMax + midRMin) / 2.0;
                break;
            } else if (!condition1) {
                midL1Max = midL1 - 1;
            } else if (!condition2) {
                midL1Min = midL1 + 1;
            }
        }

        return median;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    // Find the maximum area
    double result = solution.findMedianSortedArrays(nums1, nums2);

    // Print the result
    cout << result << "\n";

    return 0;
}