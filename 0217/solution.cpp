#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n) ~ O(n), where n is the size of the input vector nums. We iterate through
// nums once, and each unordered_set insert is O(1) amortized average-case (worst case O(n) per
// insert under hash collisions, though this is rare in practice), giving O(n) total.
// Space Complexity: O(n), where n is the size of the input vector nums. In the worst case (no
// duplicates), numsSet grows to hold all n elements.

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        // Use an unordered_set to track unique elements
        unordered_set<int> numsSet;

        // Reserve space to avoid multiple reallocations
        numsSet.reserve(nums.size());

        // Here auto is "int"
        for (const auto& num : nums) {
            numsSet.insert(num);
        }

        if (numsSet.size() < nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};

// Time Complexity: O(n log n + n) ~ O(n log n), where n is the size of the input vector nums.
// sort() costs O(n log n) (the dominant term), and the subsequent unique() + erase() pass to drop
// duplicates costs O(n).
// Space Complexity: O(log n), where n is the size of the input vector nums. sort(), unique(), and
// erase() all operate in place on nums (no auxiliary buffer proportional to n), but std::sort's
// typical introsort implementation uses O(log n) recursion stack space in the worst case.

// class Solution {
//   public:
//     bool containsDuplicate(vector<int>& nums) {
//         // Here auto is "size_t"
//         auto numsSize = nums.size();

//         // Sort the vector, as unique requires sorted input to remove duplicates correctly
//         sort(nums.begin(), nums.end());

//         // Use unique to remove duplicates and erase the redundant elements
//         nums.erase(unique(nums.begin(), nums.end()), nums.end());

//         if (nums.size() < numsSize) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// };

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3};

    // Check for duplicates
    bool hasDuplicate = solution.containsDuplicate(nums);

    // Print the result
    cout << boolalpha << hasDuplicate << "\n";

    return 0;
}