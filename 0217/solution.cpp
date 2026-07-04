#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector nums. We iterate through the
// vector once to insert its elements into the unordered_set. Space Complexity: O(n), where n is the
// size of the input vector nums. We create an unordered_set to store unique elements.

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

// Time Complexity: O(n log n), where n is the size of the input vector nums. We sort the vector,
// which takes O(n log n) time, and then iterate through it to check for duplicates, which takes
// O(n) time. Space Complexity: O(1) if we ignore the space used by the sorting algorithm, or O(n)
// if we consider the space used by the sorting algorithm.

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