#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int numsS = static_cast<int>(nums.size());
        vector<int> result;
        result.reserve(numsS - k + 1);
        deque<int> candidate;
        int left = 0;
        for (int right = 0; right < numsS; ++right) {
            while (!candidate.empty() && nums[candidate.back()] <= nums[right]) {
                candidate.pop_back();
            }
            candidate.push_back(right);
            if (right >= k - 1) {
                result.push_back(nums[candidate.front()]);
                if (left == candidate.front()) {
                    candidate.pop_front();
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {9, 3, 2, 1};
    int k = 2;

    // Find the maximum sliding window
    vector<int> result = solution.maxSlidingWindow(nums, k);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}