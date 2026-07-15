#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is nums.size(). The single loop is O(n) (one
// comparison and at most one swap per element). reverse(nums.begin(), nums.end()) afterward is
// another O(n) pass (n/2 element swaps). Total: O(n).
// Space Complexity: O(1). Only numsSizeInt, k, removes, and swapIndex are used; swap() and
// reverse() both operate in place on nums, with no auxiliary structure scaling with n.

// class Solution {
//   public:
//     int removeElement(vector<int>& nums, int val) {
//         int numsSizeInt = static_cast<int>(nums.size());
//         int k = 0;
//         int removes = 0;
//         int swapIndex = 0;

//         for (int i = 0; i < numsSizeInt; ++i) {
//             if (nums[i] == val) {
//                 swap(nums[i], nums[swapIndex]);
//                 swapIndex++;
//                 removes++;
//             }
//         }

//         k = numsSizeInt - removes;
//         reverse(nums.begin(), nums.end());

//         return k;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n), where n is nums.size(). A single forward pass: for each element, one
// comparison, and at most one O(1) write to nums[k]. No second pass is needed.
// Space Complexity: O(1). Only k is used as extra state; nums is modified in place with no
// additional buffer proportional to n.

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        // Here auto is "int"
        for (auto& num : nums) {
            if (num != val) {
                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    // Remove the specified value from the vector
    int result = solution.removeElement(nums, val);

    // Print the result
    cout << result << "\n";

    // Print the modified vector
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}