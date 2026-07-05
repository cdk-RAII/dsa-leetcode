#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector nums. We iterate through the
// vector once to find the two indices. Space Complexity: O(n), where n is the size of the input
// vector nums. We create an unordered_map to store the elements and their indices.
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int> diff;
        diff.reserve(nums.size());

        // Here auto is "int"
        for (auto idx = 0; idx < static_cast<int>(nums.size()); ++idx) {
            if (diff.contains(nums[idx])) {
                indices.push_back(diff[nums[idx]]);
                indices.push_back(idx);
                return indices;
            } else {
                diff[target - nums[idx]] = idx;
            }
        }

        return indices;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Find the two sum
    vector<int> result = solution.twoSum(nums, target);

    // Print the result
    cout << "[" << result[0] << ", " << result[1] << "]\n";

    return 0;
}