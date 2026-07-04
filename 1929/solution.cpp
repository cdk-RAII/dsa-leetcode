#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector nums. We iterate through the
// vector once to copy its elements and once more to append them to the result. Space Complexity:
// O(n), where n is the size of the input vector nums. We create a new vector ans to store the
// concatenated result.
class Solution {
  public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        // Reserve space for the concatenated result to avoid multiple reallocations
        ans.reserve(nums.size() * 2);

        // Here auto is "int"
        for (const auto& num : nums) {
            ans.push_back(num);
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
    cout << "[";
    for (auto i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}