#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        // Reserve space for the concatenated result to avoid multiple reallocations
        ans.reserve(nums.size() * 2);

        for (int i : nums) {
            ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 1, 6, 3};

    // Get the concatenated result
    vector<int> result = solution.getConcatenation(nums);

    // Print the result
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}