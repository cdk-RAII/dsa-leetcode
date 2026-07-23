#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O((n - k)/2 + k/2 + n/2) ~ O(n), where n is the size of the input vector nums.
// Computing k % numsSize costs O(1). The first call to mReverse() reverses the first n - k
// elements, requiring O((n - k) / 2) swaps. The second call reverses the last k elements,
// requiring O(k / 2) swaps. The final call reverses the entire array, requiring O(n / 2) swaps.
// Summing all phases gives O((n - k)/2 + k/2 + n/2), which simplifies to O(n).
// Space Complexity: O(1), where n is the size of the input vector nums. The algorithm performs all
// reversals in place using only a constant amount of extra space for a few integer variables
// (numsSize, k, start, and end). No additional data structures whose size depends on n are
// allocated.

class Solution {
  public:
    void mReverse(vector<int>& nums, int start, int end) {
        while (end > start) {
            swap(nums[start], nums[end]);
            end--;
            start++;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int numsSize = static_cast<int>(nums.size());
        k = k % numsSize;
        mReverse(nums, 0, numsSize - k - 1);
        mReverse(nums, numsSize - k, numsSize - 1);
        mReverse(nums, 0, numsSize - 1);
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Rotate the array
    solution.rotate(nums, k);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}