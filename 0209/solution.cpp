#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int numsS = static_cast<int>(nums.size());
        int minLength = 0;
        int left = 0;
        int currentSum = 0;
        for (int right = 0; right < numsS; ++right) {
            currentSum += nums[right];
            while (currentSum >= target) {
                if (right - left + 1 < minLength || minLength == 0) {
                    minLength = right - left + 1;
                }
                currentSum -= nums[left];
                left++;
            }
        }
        return minLength;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    // Find the minimal length of a contiguous subarray of which the sum is at least target
    int result = solution.minSubArrayLen(target, nums);

    // Print the result
    cout << result << "\n";

    return 0;
}