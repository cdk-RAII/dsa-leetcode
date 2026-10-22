#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsS = static_cast<int>(nums.size());
        unordered_map<int, int> diff;
        diff.reserve(numsS);

        for (int idx = 0; idx < numsS; ++idx) {
            if (diff.contains(nums[idx])) {
                return {diff[nums[idx]], idx};
            }

            diff[target - nums[idx]] = idx;
        }

        return {};
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