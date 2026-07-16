#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n log n + n²) ~ O(n²), where n is the size of the input vector nums. The
// initial sort(nums.begin(), nums.end()) costs O(n log n). The outer for loop executes at most n
// times. For each iteration, the two-pointer search moves the left pointer only to the right and
// the right pointer only to the left. Across a single iteration of the outer loop, each pointer
// traverses the remaining portion of the array at most once, including the duplicate-skipping
// loops, giving O(n) work. Therefore, the nested search contributes O(n²). Summing both phases
// gives O(n log n + n²), which simplifies to O(n²).
// Space Complexity: O(1), where n is the size of the input vector nums. Aside from the output
// vector, the algorithm uses only a few integer variables (i, left, right, target, and sum). The
// temporary vector temp always stores exactly three integers, so it occupies constant space. The
// sorting is performed in place and std::sort uses O(log n) recursion stack space in a typical
// introsort implementation, but no additional data structures proportional to n are allocated.
// Therefore, the auxiliary space complexity is O(log n). If the recursion stack of std::sort is
// ignored (as is commonly done in interview settings), the algorithm uses O(1) auxiliary space.
// The output vector result is not included in the auxiliary space complexity.

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int numsSize = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numsSize - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = numsSize - 1;
            int target = 0 - nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Find the three sum
    vector<vector<int>> result = solution.threeSum(nums);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}