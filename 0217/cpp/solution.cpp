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
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    bool hasDuplicate = solution.containsDuplicate(nums);
    cout << boolalpha << hasDuplicate << "\n";
    return 0;
}