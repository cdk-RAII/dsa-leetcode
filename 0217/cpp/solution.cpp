#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> seen;
        seen.reserve(nums.size());

        for (const auto& num : nums) {
            if (seen[num]) {
                return true;
            }

            seen[num] = true;
        }

        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 1};

    // Check for duplicates
    bool hasDuplicate = solution.containsDuplicate(nums);

    // Print the result
    cout << boolalpha << hasDuplicate << "\n";

    return 0;
}