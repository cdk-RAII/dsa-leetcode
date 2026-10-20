#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        ans.reserve(nums.size() * 2);

        for (const int& num : nums) {
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
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        cout << result[i];
        if (i < static_cast<int>(result.size()) - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}