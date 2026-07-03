#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        // Use an unordered_set to track unique elements
        unordered_set<int> numsSet;

        for (int num : nums) {
            numsSet.insert(num);
        }

        if (numsSet.size() < nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        int numsSize = nums.size();

        // Sort the vector, as unique requires sorted input to remove duplicates correctly
        sort(nums.begin(), nums.end());

        // Use unique to remove duplicates and erase the redundant elements
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if (nums.size() < numsSize) {
            return true;
        } else {
            return false;
        }
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
    cout << (hasDuplicate ? "true" : "false") << endl;

    return 0;
}